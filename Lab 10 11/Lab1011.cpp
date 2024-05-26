#include "Lab1011.h"
#include "qlayout.h"
#include "qformlayout.h"
#include "qmessagebox.h"


void MaterieGUI::initGUI() {
	auto mainLy = new QHBoxLayout{};
	setLayout(mainLy);
	mainLy->addWidget(list);

	auto col1 = new QFormLayout{};

	col1->addRow("Nume", nume_line);
	col1->addRow("Profesor", profesor_line);
	col1->addRow("Ore", ore_line);
	col1->addRow(addBtn);
	col1->addRow(delBtn);
	col1->addRow(modBtn);
	mainLy->addLayout(col1);
}

void MaterieGUI::list_add() {
	list->blockSignals(true);
	list->clear();
	list->blockSignals(false);

	vector<Materie> materii = service.primeste_toate_materiile();
	string str;
	for (auto& it : materii) {
		str = "";
		str += it.getNume() + " " + it.getProfesor() + " ";
		string oreStr = std::to_string(it.getOre());
		str += oreStr;
		list->addItem(QString::fromStdString(str));

	}
}



void MaterieGUI::initConnect() {
	QWidget::connect(list, &QListWidget::itemSelectionChanged, [&]() {
		auto lst = list->selectedItems();
		auto item = lst.at(0);
		auto line = (item->text()).toStdString();


		int i = 0;
		string nume = "", profesor = "", ore = "";
		for (; line[i] != ' ' && line[i] != NULL; i++)
			nume += line[i];
		i++;
		for (; line[i] != ' ' && line[i] != NULL; i++)
			profesor += line[i];
		i++;
		for (; line[i] != ' ' && line[i] != NULL; i++)
			ore += line[i];

		nume_line->setText(QString::fromStdString(nume));
		profesor_line->setText(QString::fromStdString(profesor));
		ore_line->setText(QString::fromStdString(ore));
		});

	QWidget::connect(addBtn, &QPushButton::clicked, [&]() {
		auto nume = (nume_line->text()).toStdString();
		auto profesor = profesor_line->text().toStdString();
		auto ore = ore_line->text().toStdString();
		if (ore == "")
			ore = "1";
		int oreInt = stoi(ore);

		try {
			service.addMaterieService(nume, profesor, oreInt);
			list_add();
		}
		catch (ValidationException& e){
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.getErrorMessages()));
		}


		});

	QWidget::connect(delBtn, &QPushButton::clicked, [&]() {
		auto nume = (nume_line->text()).toStdString();
		auto profesor = profesor_line->text().toStdString();

		try {
			service.delete_materie(nume, profesor);
			list_add();
		}
		catch (std::invalid_argument& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.what()));
		}
		});

	QWidget::connect(modBtn, &QPushButton::clicked, [&]() {
		auto lst = list->selectedItems();
		auto item = lst.at(0);
		auto line = (item->text()).toStdString();
		string nume = "";
		string profesor = "";
		int i = 0;
		for (; line[i] != ' '; i++)
			nume += line[i];

		i++;
		for (; line[i] != ' '; i++)
			profesor += line[i];

		string nume_nou = nume_line->text().toStdString();
		string profesor_nou = profesor_line->text().toStdString();
		int ore_nou = stoi(ore_line->text().toStdString());

		try {
			service.update_materie(nume, profesor, nume_nou, profesor_nou, ore_nou);
			list_add();
		}
		catch (ValidationException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.getErrorMessages()));
		}
	
		
		});
}

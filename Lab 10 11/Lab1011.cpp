#include "Lab1011.h"
#include "qlayout.h"
#include "qformlayout.h"


void MaterieGUI::initGUI() {
	auto mainLy = new QHBoxLayout{};
	setLayout(mainLy);
	mainLy->addWidget(list);

	auto col1 = new QFormLayout{};

	col1->addRow("Nume", nume_line);
	col1->addRow("Profesor", profesor_line);
	col1->addRow("Ore", ore_line);
	col1->addRow(addBtn);
	mainLy->addLayout(col1);
}

void MaterieGUI::list_add() {
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
		auto ore = stoi(ore_line->text().toStdString());

		service.addMaterieService(nume, profesor, ore);



		});
}

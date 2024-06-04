#include "Lab1011.h"
#include "qlayout.h"
#include "qformlayout.h"
#include "qmessagebox.h"
#include <iostream>
#include <windows.h>
#include "qlabel.h"

void MaterieGUI::initGUI() {
	auto mainLy = new QHBoxLayout{};
	setLayout(mainLy);
	mainLy->addWidget(list);
	mainLy->addWidget(table);

	auto col1 = new QFormLayout{};

	col1->addRow("Nume", nume_line);
	col1->addRow("Profesor", profesor_line);
	col1->addRow("Ore", ore_line);
	col1->addRow(addBtn);
	col1->addRow(delBtn);
	col1->addRow(modBtn);
	col1->addRow(exitBtn);
	mainLy->addLayout(col1);

	auto col2 = new QFormLayout{};
	col2->addRow(sortBtn);
	col2->addRow(filterBtn);
	col2->addRow(profesor_filter_line);
	col2->addRow(resetBtn);
	col2->addWidget(new QLabel{ "Afisare nr materii" });
	col2->addRow(ascBtn);	
	col2->addRow(oopBtn);
	col2->addRow(bioBtn);
	col2->addRow(contractBtn);

	mainLy->addLayout(col2);
}



void MaterieGUI::list_add(vector<Materie> materii) {
	list->blockSignals(true);
	list->clear();
	list->blockSignals(false);

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
			list_add(service.primeste_toate_materiile());
			initTable();
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
			list_add(service.primeste_toate_materiile());
			initTable();
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
			list_add(service.primeste_toate_materiile());
			initTable();
		}
		catch (ValidationException& e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.getErrorMessages()));
		}
		
		
		});

	QWidget::connect(exitBtn, &QPushButton::clicked, [&]() {

		QMessageBox::information(nullptr, "Exit", "Program will close.");
		close();
		});

	QWidget::connect(sortBtn, &QPushButton::clicked, [&]() {

		vector<Materie> sorted = service.sort_func(1);
		list_add(sorted);
		});

	QWidget::connect(filterBtn, &QPushButton::clicked, [&]() {

		auto profesor = profesor_filter_line->text().toStdString();
		vector<Materie> filtered = service.filter_by_profesor(profesor);
		list_add(filtered);
		});

	QWidget::connect(resetBtn, &QPushButton::clicked, [&]() {
		list_add(service.primeste_toate_materiile());
		});

	QWidget::connect(ascBtn, &QPushButton::clicked, [&]() {
		int nr = service.nr_materii("ASC");
		string mesaj = "ASC apare de ";
		auto nrStr = std::to_string(nr);
		mesaj += nrStr;
		mesaj += " ori!";
		QMessageBox::information(nullptr, "Nr. ASC", QString::fromStdString(mesaj));
		});

	QWidget::connect(oopBtn, &QPushButton::clicked, [&]() {
		int nr = service.nr_materii("POO");
		string mesaj = "POO apare de ";
		auto nrStr = std::to_string(nr);
		mesaj += nrStr;
		mesaj += " ori!";
		QMessageBox::information(nullptr, "Nr. POO", QString::fromStdString(mesaj));
		});

	QWidget::connect(bioBtn, &QPushButton::clicked, [&]() {
		int nr = service.nr_materii("Biologie");
		string mesaj = "Bio apare de ";
		auto nrStr = std::to_string(nr);
		mesaj += nrStr;
		mesaj += " ori!";
		QMessageBox::information(nullptr, "Nr. Bio", QString::fromStdString(mesaj));
		});

	QWidget::connect(contractBtn, &QPushButton::clicked, [&]() {
		contractWidget->show();
		});

}

void MaterieGUI::initTable() {
	table->setRowCount(service.primeste_toate_materiile().size());
	table->setColumnCount(3);
	int row = 0;
	for (auto& it : service.primeste_toate_materiile()) {
		table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(it.getNume())));
		table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(it.getProfesor())));
		table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(it.getOre()))));
		row++;
	}
}


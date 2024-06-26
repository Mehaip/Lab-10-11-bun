#include "ContractGUI.h"
#include "Lab1011.h"
#include "qlayout.h"
#include "qformlayout.h"
#include "qmessagebox.h"
#include <iostream>
#include <windows.h>
#include "qlabel.h"



void ContractGUI::initGUI() {
	auto mainLy = new QHBoxLayout{};
	setLayout(mainLy);
	mainLy->addWidget(list);
	
	auto col1 = new QFormLayout{};
	col1->addRow("Nume", nume_line);
	col1->addRow("Profesor", profesor_line);
	col1->addRow(addBtn);
	col1->addRow(addRandomBtn);
	col1->addRow("Random elements", nr_line);
	col1->addRow(emptyBtn);
	col1->addRow(exportBtn);
	mainLy->addLayout(col1);

}

void ContractGUI::initConnect() {
	QWidget::connect(addBtn, &QPushButton::clicked, [&]() {
		auto nume = (nume_line->text()).toStdString();
		auto profesor = profesor_line->text().toStdString();

		try {
			service.contract_add(nume, profesor);
			list_add(service.contract_get_all());
		}
		catch (std::invalid_argument e) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.what()));
		}
		});

	QWidget::connect(addRandomBtn, &QPushButton::clicked, [&]() {
		auto nr = nr_line->text().toStdString();

		if (nr == "")
			QMessageBox::warning(this, "Warning", QString::fromStdString("Te rog adauga un numar de materii."));
		else
		{
			int numar = stoi(nr);
			try {
				service.contract_random(numar);
				list_add(service.contract_get_all());
			}
			catch (std::invalid_argument e) {
				QMessageBox::warning(this, "Warning", QString::fromStdString(e.what()));
			}
		}
		});


	QWidget::connect(emptyBtn, &QPushButton::clicked, [&]() {
		service.contract_empty();
		list_add(service.contract_get_all());
		});

	QWidget::connect(exportBtn, &QPushButton::clicked, [&]() {
		QMessageBox::information(nullptr, "Info", "Materii exportate cu succes in fisierul site.html!");
		service.contract_export("site.html");
		});
}

void ContractGUI::list_add(vector<Materie> materii) {
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
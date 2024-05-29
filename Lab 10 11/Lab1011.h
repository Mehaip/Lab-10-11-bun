#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1011.h"
#include "Service.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "qtablewidget.h"

class MaterieGUI : public QWidget
{
public:
	MaterieGUI(MaterieService& service) : service{ service } {
		initGUI();
		list_add(service.primeste_toate_materiile());
		initConnect();
		initTable();
	};

private:
	MaterieService& service;
	void initGUI();
	void list_add(vector<Materie> a);
	void initConnect();
	void initTable();
	QListWidget* list = new QListWidget{};
	QLineEdit* nume_line = new QLineEdit{};
	QLineEdit* profesor_line = new QLineEdit{};
	QLineEdit* ore_line = new QLineEdit{};
	QPushButton* addBtn = new QPushButton{"&Add"};
	QPushButton* delBtn = new QPushButton{ "&Delete" };
	QPushButton* modBtn = new QPushButton{ "&Modify" };
	QPushButton* exitBtn = new QPushButton{ "&Exit" };

	QPushButton* sortBtn = new QPushButton{ "&Sort by name" };
	QPushButton* filterBtn = new QPushButton{ "&Filter by profesor" };
	QPushButton* resetBtn = new QPushButton{ "&Reset" };
	QLineEdit* profesor_filter_line = new QLineEdit{};

	QPushButton* ascBtn = new QPushButton{ "ASC" };
	QPushButton* oopBtn = new QPushButton{ "OOP" };
	QPushButton* bioBtn = new QPushButton{ "Biologie" };

	QTableWidget* table = new QTableWidget{};

};

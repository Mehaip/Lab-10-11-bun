#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Lab1011.h"
#include "Service.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "qtablewidget.h"

class ContractGUI: public QWidget
{
public:
	ContractGUI(MaterieService& service) : service{ service } {
		initGUI();
		initConnect();
	}

private:
	MaterieService& service;
	void initGUI();
	void initConnect();
	void list_add(vector<Materie> materii);

	QListWidget* list = new QListWidget{};
	QLineEdit* nume_line = new QLineEdit{};
	QLineEdit* profesor_line = new QLineEdit{};

	QPushButton* addBtn = new QPushButton{ "&Add" };
	QPushButton* addRandomBtn = new QPushButton{ "&Add random" };
	QPushButton* emptyBtn = new QPushButton{ "&Empty" };
	QPushButton* exportBtn = new QPushButton{ "&Export" };
	QLineEdit* nr_line = new QLineEdit{};
};


#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1011.h"
#include "Service.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qpushbutton.h"

class MaterieGUI : public QWidget
{
public:
	MaterieGUI(MaterieService& service) : service{ service } {
		initGUI();
		list_add();
		initConnect();
	};

private:
	MaterieService& service;
	void initGUI();
	void list_add();
	void initConnect();
	QListWidget* list = new QListWidget{};
	QLineEdit* nume_line = new QLineEdit{};
	QLineEdit* profesor_line = new QLineEdit{};
	QLineEdit* ore_line = new QLineEdit{};
	QPushButton* addBtn = new QPushButton{};

};

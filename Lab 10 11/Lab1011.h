#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1011.h"
#include "Service.h"
#include "qlistwidget.h"

class MaterieGUI : public QWidget
{
public:
	MaterieGUI(MaterieService& service) : service{ service } {
		initGUI();
	};

private:
	MaterieService& service;
	void initGUI();
	QListWidget* list = new QListWidget{};

};

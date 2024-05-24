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
	mainLy->addLayout(col1);
}

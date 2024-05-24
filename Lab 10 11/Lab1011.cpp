#include "Lab1011.h"
#include "qlayout.h"


void MaterieGUI::initGUI() {
	auto mainLy = new QHBoxLayout{};
	setLayout(mainLy);
	mainLy->addWidget(list);
}

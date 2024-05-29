#include "MaterieDTO.h"

MaterieDTO::MaterieDTO() {};

MaterieDTO::MaterieDTO(const std::string& nume_materie, int count) : nume_materie{ nume_materie }, count{ count } {};

void MaterieDTO::incCount() {
	count++;
}

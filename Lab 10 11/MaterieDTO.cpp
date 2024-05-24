#include "MaterieDTO.h"

MaterieDTO::MaterieDTO() {};

MaterieDTO::MaterieDTO(const std::string& nume_materie, int count) : nume_materie{ nume_materie }, count{ count } {};

void MaterieDTO::incCount() {
	count++;
}

std::string MaterieDTO::get_nume() const {
	return nume_materie;
}

int MaterieDTO::get_aparitii() const {
	return count;
}
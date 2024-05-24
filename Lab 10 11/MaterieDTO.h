#pragma once
#include <string>
class MaterieDTO
{
public:
	std::string nume_materie{};
	int count{};

	///constructor fara parametri
	MaterieDTO();

	///constructor cu parametri
	MaterieDTO(const std::string& nume_materie, int count);

	///incrementam aparitiile
	void incCount();

	///getter pentru nume
	std::string get_nume() const;

	///getter pentru aparitii
	int get_aparitii() const;

};


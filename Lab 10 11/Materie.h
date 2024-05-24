#pragma once

#include <iostream>
#include <string>
using std::string;


class Materie {
private:
	string nume{ "" };
	string profesor{ "" };
	int ore;
public:
	Materie() = delete; ///in caz ca se creeaza o materie fara atributtes
	Materie(string nume, string profesor, int ore) : nume{ nume }, profesor{ profesor },
		ore{ ore } {
		///printf("Materie created!\n");
	};

	///facem copie la o materie

	Materie(const Materie& copy) : nume{ copy.nume }, profesor{ copy.profesor }, ore{ copy.ore }
	{
		///printf("Copy constructor called!\n");
	};

	// Getters
	// const -> nu modific obiectul

	string getNume() const;
	string getProfesor() const;
	int getOre() const;

	// Setters

	void setNume(string nume);
	void setProfesor(string profesor);
	void setOre(int ore);

	// Operatori

	bool operator==(const Materie& materie) const {
		return nume == materie.nume && profesor == materie.profesor && ore == materie.ore;
	};

	friend std::ostream& operator<<(std::ostream& os, const Materie& materie) {
		os << "Materie(" << materie.getNume() << " " << materie.getProfesor() << " " << materie.getOre() << ")\n";
		return os;
	}




};
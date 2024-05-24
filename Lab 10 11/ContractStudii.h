#pragma once
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <vector>
#include "Materie.h"
#include "MaterieDTO.h"
using std::vector;

/*
	Clasa contract reprezinta un contract de studiu, care contine un vector de materii.
*/
class Contract {
private:
	vector<Materie> materii_contract;

public:
	Contract() {
		materii_contract.clear();
	};

	/// Primeste toate materiile din contract
	vector<Materie>& primeste_toate();

	/// Adauga o materie in contract
	void add_materie_to_contract(const Materie& m);

	/// Goleste contractul
	void empty_contract();

	/// Primeste lista si adauga un numar introdus de utilizator de materii random in contract
	void add_random_contracts(const vector<Materie>& lista, int number_to_add);

	/// Salveaza contractul in fisier
	void save_to_file(string& filename);

	/// Afiseaza fiecare nume de materie din contract si de cate ori apare
	vector<MaterieDTO> raport();
};
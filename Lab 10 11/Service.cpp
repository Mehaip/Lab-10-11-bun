#include <vector>
#include "Service.h"
#include <algorithm>
using std::vector;


const vector<Materie>& MaterieService::primeste_toate_materiile() {
	return repo.primeste_toate_materiile(); //de ce nu this-> ? raspuns: nu e nicio diferenta, programul il gaseste oricum
}

void MaterieService::addMaterieService(string nume, string profesor, int ore) {
	try {
		Materie materie{ nume, profesor, ore };
		val.valideaza(materie);
		repo.add_materie(materie);
		undoActions.push_back(new UndoAdd(repo, materie));
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}
}


void MaterieService::add_default() {
	try {
		addMaterieService("ASC", "Mircea", 32);
		addMaterieService("POO", "Ana", 10);
		addMaterieService("Mate", "Larisa", 15);
		addMaterieService("Logica", "Mihai", 24);
		addMaterieService("Fizica", "Ion", 20);
		addMaterieService("Chimie", "Mircea", 30);
		addMaterieService("Biologie", "Maria", 25);
		addMaterieService("POO", "Cocrea", 60);
		addMaterieService("Sport", "Zulnia", 4);
		addMaterieService("Biologie", "Paduraru", 10);
		addMaterieService("Biologie", "Mihail", 6);
		addMaterieService("Sport", "Andrei", 5);
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}

}

void MaterieService::delete_materie(string nume, string profesor) {
	try {
		if (get_materie_position(nume, profesor) == -1)
			throw std::invalid_argument("Materia nu exista in lista.\n");
		int materie_position = get_materie_position(nume, profesor);
		Materie materie_stearsa = this->primeste_toate_materiile()[materie_position];
		repo.delete_materie(materie_position);
		undoActions.push_back(new UndoDel(repo, materie_stearsa, materie_position));
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}
}

int MaterieService::get_materie_position(string nume, string profesor) const {
	return repo.get_materie_position(nume, profesor);

}

void MaterieService::update_materie(string nume, string profesor, string new_nume, string new_profesor, int new_ore) {
	try {
		if (get_materie_position(nume, profesor) == -1)
			throw std::invalid_argument("Materia nu exista in lista.\n");
		Materie materie = Materie{ new_nume, new_profesor, new_ore };
		int ore_vechi = this->primeste_toate_materiile()[get_materie_position(nume, profesor)].getOre();
		Materie materie_veche = Materie{ nume, profesor, ore_vechi };
		val.valideaza(materie);

		int materie_position = get_materie_position(nume, profesor);
		repo.update_materie(materie_position, new_nume, new_profesor, new_ore);
		undoActions.push_back(new UndoMod(repo, materie, materie_veche));
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}
}




const vector<Materie> MaterieService::filter_by_ore(int ore) {
	vector<Materie> materii = repo.primeste_toate_materiile();
	vector<Materie> materii_filtrate;

	copy_if(materii.begin(), materii.end(), std::back_inserter(materii_filtrate),
		[ore](const Materie& m) {return m.getOre() <= ore; });


	return materii_filtrate;
}

const vector<Materie> MaterieService::filter_by_profesor(string profesor) {
	vector<Materie> materii = repo.primeste_toate_materiile();
	vector<Materie> materii_filtrate;

	copy_if(materii.begin(), materii.end(), std::back_inserter(materii_filtrate),
		[profesor](const Materie& m) {return m.getProfesor() == profesor; });

	return materii_filtrate;
}

bool crit_1(Materie a, Materie b) {
	return a.getNume() < b.getNume();
}

bool crit_2(Materie a, Materie b) {
	return a.getOre() < b.getOre();
}

bool crit_3(Materie a, Materie b) {
	return a.getProfesor() < b.getProfesor();
}

const vector<Materie> MaterieService::sort_func(int criteriu) {
	vector<Materie> materii = primeste_toate_materiile();
	if (criteriu == 1)
		sort(materii.begin(), materii.end(), crit_1);
	else if (criteriu == 2)
		sort(materii.begin(), materii.end(), crit_2);
	else if (criteriu == 3)
		sort(materii.begin(), materii.end(), crit_3);

	return materii;

}

void MaterieService::undo() {
	try {
		if (undoActions.empty())
			throw ("Nu mai exista operatii de undo.\n");
		undoActions.back()->doUndo();
		undoActions.pop_back();
	}
	catch (std::runtime_error& e) {
		std::cout << e.what();
	}
}


void MaterieService::contract_add(string nume, string profesor) {

	int value = get_materie_position(nume, profesor);
	if (value == -1)
		throw std::invalid_argument("Materia nu exista in lista.\n");
	else {
		Materie m = primeste_toate_materiile()[value];
		contract.add_materie_to_contract(m);
	}

}

void MaterieService::contract_empty() {
	contract.empty_contract();
}

void MaterieService::contract_random(int number) {
	if (number > primeste_toate_materiile().size())
		throw std::invalid_argument("Numarul introdus depaseste marimea!\n");

	contract.add_random_contracts(primeste_toate_materiile(), number);
}

void MaterieService::contract_export(string filename) {
	contract.save_to_file(filename);
}

vector<MaterieDTO> MaterieService::contract_raport() {
	return contract.raport();
}

vector<Materie> MaterieService::contract_get_all() {
	return contract.primeste_toate();
}


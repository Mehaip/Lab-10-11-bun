#pragma once
#include "Service.h"
#include "assert.h"

class TestService {
public:
	TestService() {
		test_add();
		test_delete();
		test_modify();
		test_add_default();
		test_filter_by_ore();
		test_filter_by_profesor();
		test_sort();
		test_contract();
		test_undo();
	};
private:

	void test_add() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.addMaterieService("Aaaa", "bbbbb", 30);
		vector <Materie> materii = service.primeste_toate_materiile();
		assert(materii[0].getNume() == "Aaaa");
		assert(materii[0].getProfesor() == "bbbbb");
		assert(materii[0].getOre() == 30);
		materii[0].setNume("mircea");
		materii[0].setOre(29);
		materii[0].setProfesor("aurel");
		assert(materii[0].getNume() == "mircea");
		assert(materii[0].getProfesor() == "aurel");
		assert(materii[0].getOre() == 29);
	}

	void test_delete() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.addMaterieService("aaaa", "bbbb", 30);
		service.delete_materie("aaaa", "bbbb");
		vector <Materie> materii = service.primeste_toate_materiile();
		assert(materii.size() == 0);

	}

	void test_modify() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.addMaterieService("aaaa", "bbbb", 30);
		service.update_materie("aaaa", "bbbb", "cccc", "dddd", 49);
		vector <Materie> materii = service.primeste_toate_materiile();
		assert(materii[0].getNume() == "cccc");
		assert(materii[0].getProfesor() == "dddd");
		assert(materii[0].getOre() == 49);
	}

	void test_add_default() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.add_default();
		vector <Materie> materii = service.primeste_toate_materiile();
		assert(materii.size() == 12);
		assert(materii[11].getNume() == "Sport");
		assert(service.nr_materii("ASC") == 1);
	}

	void test_filter_by_ore() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.add_default();
		vector <Materie> materii = service.filter_by_ore(10);
		assert(materii.size() == 5);
	}

	void test_filter_by_profesor() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.add_default();
		vector <Materie> materii = service.filter_by_profesor("Paduraru");
		assert(materii.size() == 1);
	}

	void test_sort() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.add_default();
		vector <Materie> materii = service.sort_func(3);
		assert(materii[materii.size() - 1].getProfesor() == "Zulnia");
		materii = service.sort_func(1);
		assert(materii[0].getNume() == "ASC");
		materii = service.sort_func(2);
		assert(materii[0].getOre() == 4);
	}

	void test_contract() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.add_default();
		service.contract_add("ASC", "Mircea");
		service.contract_random(3);
		service.contract_empty();
		service.contract_random(4);
		vector<Materie> sir = service.contract_get_all();
		service.contract_export("Text2.txt");
		service.contract_raport();
	}

	void test_undo() {
		MaterieRepository repo;
		MaterieValidator val;
		Contract contract;
		MaterieService service(repo, val, contract);
		service.add_default();
		service.undo();
		assert(service.primeste_toate_materiile().size() == 11);
		service.delete_materie("ASC", "Mircea");
		service.undo();
		assert(service.primeste_toate_materiile().size() == 11);
		service.update_materie("ASC", "Mircea", "POO", "Ana", 20);
		service.undo();
		assert(service.get_materie_position("ASC", "Mircea") != -1);

	}

};
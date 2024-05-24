#include "Materie.h"
#include <iostream>

string Materie::getNume() const {
	return nume;
}

string Materie::getProfesor() const {
	return profesor;
}

int Materie::getOre() const {
	return ore;
}

void Materie::setNume(string Nume) {
	this->nume = Nume;
}

void Materie::setProfesor(string Profesor) {
	this->profesor = Profesor;
}

void Materie::setOre(int Ore) {
	this->ore = Ore;
}
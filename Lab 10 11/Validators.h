#pragma once
#include "Materie.h"
#include <vector>
#include <string>
using std::vector;

class ValidationException {
	vector<string> errorMsg;
public:
	ValidationException(vector<string> errorMessages) : errorMsg{ errorMessages } {};

	string getErrorMessages() {
		string fullMsg = "Errors:\n";
		for (const string e : errorMsg) {
			fullMsg += e + "\n";
		}
		return fullMsg;
	}
};

class MaterieValidator {

public:
	void valideaza(const Materie& m) {
		vector<string> errors;
		if (m.getNume().length() < 2)
			errors.push_back("Numele materiei trebuie sa aiba cel putin 2 caractere.");

		if (m.getProfesor().length() < 2)
			errors.push_back("Numele profesorului trebuei sa aiba cel putin 2 caractere");

		if (m.getOre() < 3)
			errors.push_back("O materie dureaza cel putin 4 ore.");

		if (errors.size() > 0)
			throw ValidationException(errors);
	}


};
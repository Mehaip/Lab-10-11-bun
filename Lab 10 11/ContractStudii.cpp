#include "ContractStudii.h"
#include <random>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
using namespace std;

void Contract::add_materie_to_contract(const Materie& m) {

    materii_contract.push_back(m);
}

void Contract::empty_contract() {
    materii_contract.clear();
}

vector<Materie>& Contract::primeste_toate() {
    return materii_contract;
}

void Contract::add_random_contracts(const vector<Materie>& lista, int number_of_contracts_to_add) {
    vector<int> indexes_used;
    for (; number_of_contracts_to_add > 0; number_of_contracts_to_add--) {
        int random_index = rand() % lista.size();
        // Check if random_index is already used
        if (find(indexes_used.begin(), indexes_used.end(), random_index) != indexes_used.end()) {
            number_of_contracts_to_add++;
            continue;
        }
        this->materii_contract.push_back(lista[random_index]);
        indexes_used.push_back(random_index);
    }
}

void Contract::save_to_file(string& filename) {
    std::ofstream fout(filename);
    fout << "<html>\n"
        "<body>\n"
        "<head>\n"
        "    <h3 style=\" font-family: 'Times New Roman',serif; color:black; \">Contract cu materii</h3>\n"
        "    </head>\n"
        "<style>\n"
        "    p {\n"
        "        color: #D7BDE2 ;\n"
        "        background-color: #A9CCE3 ;\n"
        "        border: 1px solid black; }\n"
        "    table,th,td{\n"
        "        border: 1px solid black;\n"
        "    }\n"
        "    th{\n"
        "        color: black;\n"
        "    }\n"
        "    body{\n"
        "        background-color: #F9FA77;\n"
        "    }\n"
        "</style>\n";
    fout << "<table>\n"
        "\n"
        "        <th>Id</th>\n"
        "        <th>Nume</th>\n"
        "        <th>Profesor</th>\n"
        "        <th>Ore</th>\n";
    int id = 1;
    for (const Materie& m : this->primeste_toate())
    {
        fout << "<tr>\n";
        fout << "<th>" << id++ << "</th>\n"
            << "<th>" << m.getNume() << "</th>\n"
            << "<th>" << m.getProfesor() << "</th>\n"
            << "<th>" << m.getOre() << "</th>\n"
            << "</tr>\n";


    }
    fout << "</table>\n"
        "\n"
        "\n"
        "</body>\n"
        "</html>";


}

vector<MaterieDTO> Contract::raport() {

    map<string, MaterieDTO> aparitii;
    const  vector<Materie>& lista = this->primeste_toate();
    for (int i = 0; i < lista.size(); i++) {
        string nume = lista[i].getNume();
        if (aparitii.find(nume) != aparitii.end())
            aparitii[nume].incCount();
        else
            aparitii[nume] = MaterieDTO(nume, 1);
    }

    vector<MaterieDTO> result;
    for (const auto& pair : aparitii) {
        result.push_back(pair.second);
    }
    return result;

}

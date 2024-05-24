#include <vector>
#include "Materie.h"
#include <map>
using std::vector;
using std::map;
class AbstractRepo {
public:
	///print all materie
	virtual const vector<Materie>& primeste_toate_materiile() const = 0;

	///add materie
	virtual void add_materie(const Materie& m) = 0;

	///inseram materie pe pozitia introdusa
	virtual void insert_materie(const Materie& m, int poz) = 0;

	///find pozitia materiei si returneaza un int
	virtual int get_materie_position(string nume, string profesor) const = 0;

	/// sterge materia in functie de pozitia primita
	virtual void delete_materie(int position) = 0;

	///modifica materia in functie de pozitia primita si noile date
	virtual void update_materie(int position, string new_nume, string new_profesor, int new_ora) = 0;

	virtual ~AbstractRepo() = default;
};


class MaterieRepository :public AbstractRepo {
private:
	vector <Materie> toateMateriile;

public:

	MaterieRepository() = default;
	MaterieRepository(const MaterieRepository& other) = delete;

	///print all materie
	virtual const vector<Materie>& primeste_toate_materiile() const override;

	///add materie
	virtual void add_materie(const Materie& m)  override;

	///inseram materie pe pozitia introdusa
	virtual void insert_materie(const Materie& m, int poz) override;

	///find pozitia materiei si returneaza un int
	virtual int get_materie_position(string nume, string profesor) const override;

	/// sterge materia in functie de pozitia primita
	virtual void delete_materie(int position) override;

	///modifica materia in functie de pozitia primita si noile date
	virtual void update_materie(int position, string new_nume, string new_profesor, int new_ora) override;

	///undo functie

	virtual ~MaterieRepository() = default;

};

class FileRepository :public MaterieRepository {
private:
	string filename;
	void load_from_file();
	void save_to_file() const;
public:
	FileRepository() = default;
	~FileRepository() override = default;

	///add materie
	void add_materie(const Materie& m)  override {
		MaterieRepository::add_materie(m);
		save_to_file();
	};

	///inseram materie pe pozitia introdusa
	void insert_materie(const Materie& m, int poz) override {
		MaterieRepository::insert_materie(m, poz);
		save_to_file();
	};

	/// sterge materia in functie de pozitia primita
	void delete_materie(int position) override {
		MaterieRepository::delete_materie(position);
		save_to_file();
	};

	///modifica materia in functie de pozitia primita si noile date
	void update_materie(int position, string new_nume, string new_profesor, int new_ora) override {
		MaterieRepository::update_materie(position, new_nume, new_profesor, new_ora);
		save_to_file();
	};

};

class ProbabilityRepo :public AbstractRepo {
private:
	map<int, Materie> elems;
	float prob;
	void det_luck() const;
public:
	ProbabilityRepo() = default;
	explicit ProbabilityRepo(float chance) : prob{ chance } {};


	///print all materie
	const vector<Materie>& primeste_toate_materiile() const override;

	///add materie
	void add_materie(const Materie& m)  override;

	/// sterge materia in functie de pozitia primita
	void delete_materie(int position) override;

	///modifica materia in functie de pozitia primita si noile date
	void update_materie(int position, string new_nume, string new_profesor, int new_ora) override;

	void insert_materie(const Materie& m, int poz) override;

	int get_materie_position(string nume, string profesor) const override;




};
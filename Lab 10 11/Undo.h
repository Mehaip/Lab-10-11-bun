#pragma once

class ActiuneUndo {
public:
    virtual void doUndo() = 0;
    virtual ~ActiuneUndo() = default;

};

class UndoAdd :public ActiuneUndo {
private:
    AbstractRepo& repo;
    Materie materie_adaugata;
public:
    UndoAdd(AbstractRepo& r, Materie last) : repo{ r }, materie_adaugata{ last } {};
    void doUndo() override {
        auto& materii = repo.primeste_toate_materiile();
        auto it = find(materii.begin(), materii.end(),
            materie_adaugata);

        int poz = static_cast<int>(std::distance(materii.begin(), it));
        repo.delete_materie(poz);

    }
};

class UndoMod :public ActiuneUndo {
private:
    AbstractRepo& repo;
    Materie materie_modificata;
    Materie materie_veche;
public:
    class UndoMod(AbstractRepo& repo, const Materie& m, const Materie& m_v) :
        repo {
        repo
    }, materie_modificata{ m }, materie_veche{ m_v } {};
        void doUndo() override {
            int poz = repo.get_materie_position(materie_modificata.getNume(), materie_modificata.getProfesor());
            repo.update_materie(poz, materie_veche.getNume(), materie_veche.getProfesor(),
                materie_veche.getOre());
        }


};

class UndoDel : public ActiuneUndo {
private:
    AbstractRepo& repo;
    Materie materie_stearsa;
    int pozitia_materiei_sterse;
public:
    UndoDel(AbstractRepo& repos, const Materie& materie_stearsa, int poz) : repo{ repos }, materie_stearsa{ materie_stearsa },
        pozitia_materiei_sterse{ poz } {};
    void doUndo() override {
        repo.insert_materie(materie_stearsa, pozitia_materiei_sterse);
    }
};
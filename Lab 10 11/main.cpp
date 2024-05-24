#include "Lab1011.h"
#include <QtWidgets/QApplication>
#include "Service.h"

int main(int argc, char *argv[])
{
    MaterieRepository repo;
    MaterieValidator val;
    Contract contract;
    MaterieService service{ repo, val, contract };

    QApplication a(argc, argv);
    MaterieGUI w{service};
    w.show();
    return a.exec();
}

#include "Lab1011.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "testService.h"

int main(int argc, char *argv[])
{
    TestService testS;
   /// TestRepo testR;
    FileRepository repo;
    MaterieValidator val;
    Contract contract;
    MaterieService service{ repo, val, contract };

    QApplication a(argc, argv);
    ContractGUI c{ service };
    MaterieGUI w{service, c};

    w.show();
    return a.exec();
}

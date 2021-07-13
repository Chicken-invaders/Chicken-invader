#include <QApplication>
#include "View.h"
#include "Menu.h"

//View * v;
Menu * m;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    v = new View();
//    v->show();
        m=new Menu();
        m->show();
    return a.exec();
}

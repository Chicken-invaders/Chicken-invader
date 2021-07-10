#include <QApplication>
#include "View.h"

View * v;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    v = new View();
    v->show();
    return a.exec();
}

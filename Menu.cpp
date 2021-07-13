#include "Menu.h"

Menu::Menu()
{
    mscene = new QGraphicsScene();
    mscene->setSceneRect(0,0,1920,1080);
    setScene(mscene);

    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);

    //set background
    setBackgroundBrush(QBrush(QImage(":/ images/main_menu.png")));

    newGameButton=new QPushButton();
    newGameButton->setGeometry(960,540,560,80);

}

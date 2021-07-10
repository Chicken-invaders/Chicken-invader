#include "Controller.h"

Controller::Controller() : QGraphicsView()
{
setScene(v->scene);
setBackgroundBrush(QBrush(QImage(":/ images/background.jpg")));

//fix size
setFixedSize(1920,1080);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

timer = new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(add()));
timer->start(50);
}

Controller::~Controller()
{

}

void Controller::add()
{
    v->addChicken(20);
}





#include "Egg.h"
#include "View.h"
extern View * v;
Egg::Egg()
{

timer=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(moveDown()));
timer->start(50);

QTimer *time=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(deletefEgg()));
time->start(20);

}

Egg::~Egg()
{
    delete timer;
}

void Egg::moveDown()
{
    if(this->y()<1000)
    {  setPixmap(QPixmap(":/ images/egg2.png"));

      moveBy(0,+27);

    }
    else
    {
        disconnect(timer , SIGNAL(timeout()) , this , SLOT(moveDown()));
        convertedEggTime=v->sec;
        setPixmap(QPixmap(":/ images/fEgg.png"));//convert picture of fried egg
    }



    if(y()>1080)
      delete this;
}

void Egg::deletefEgg()
{
    if(convertedEggTime+1==v->sec)
        delete this;
}


#include "Meat.h"
#include "View.h"
extern View * v;
Meat::Meat()
{
setPixmap(QPixmap(":/ images/meat.png"));
timer=new QTimer;
connect(timer , SIGNAL(timeout()) , this , SLOT(moveDown()));
timer->start(50);

}

Meat::~Meat()
{
    delete timer;
}

void Meat::generateMeat(int x ,int y)
{
    v->meat=new Meat();
    v->scene->addItem(v->meat);
    v->meat->setPos(x,y);
}

void Meat::moveDown(){

   moveBy(0,+27);

if(y()>1080)
    delete this;

}

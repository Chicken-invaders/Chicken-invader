#include "Egg.h"
#include "View.h"
extern View * v;
Egg::Egg()
{
    setPixmap(QPixmap(":/ images/egg2.png"));
timer=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(moveDown()));
timer->start(50);
//generateEgg();

}

Egg::~Egg()
{

}

void Egg::moveDown()
{
    moveBy(0,+27);
  if(y()>1080)
    delete this;
}

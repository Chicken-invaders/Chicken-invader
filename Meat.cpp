#include "Meat.h"

Meat::Meat()
{
setPixmap(QPixmap(":/ images/meat.png"));
timer=new QTimer;
connect(timer , SIGNAL(timeout()) , this , SLOT(moveDown()));
timer->start(50);

}

void Meat::moveDown(){

   moveBy(0,+27);
if(y()>1080)
    delete this;

}

#include "Gift.h"

Gift::Gift()
{

setPixmap(QPixmap(":/ images/gift.png"));
    timer=new QTimer();
    connect(timer , SIGNAL(timeout()) , this , SLOT(moveDown()));
    timer->start(50);

}

void Gift::moveDown()
{
     moveBy(0,+27);
     if(y()>1080)
         delete this;

}

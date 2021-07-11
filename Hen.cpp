#include "Hen.h"
#include "QDebug"
Hen::Hen(int row) : Chicken(row)
{
    this->lives = 2;
    this->counter = 0;
    this->counter2=0;
    this->stopCounter = 0;
    qDebug() << lives;
}

void Hen::motionWings()
{
    counter++;
    if(counter % 4 == 0)
    setPixmap(QPixmap(":/ images/hen0.png"));
    else  if(counter % 4 == 1)
    setPixmap(QPixmap(":/ images/hen1.png"));
    else  if(counter % 4 == 2)
    setPixmap(QPixmap(":/ images/hen2.png"));
    else  if(counter % 4 == 3)
        setPixmap(QPixmap(":/ images/hen1.png"));
}

void Hen::moveDown()
{
    moveBy(0 , (row+1) * 5);
    stopCounter++;
    if(stopCounter == 30){
          disconnect(moveTimer , SIGNAL(timeout()) , this , SLOT(moveDown()));

   }
}

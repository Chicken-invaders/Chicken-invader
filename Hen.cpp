#include "Hen.h"

Hen::Hen(int row) : Chicken(row)
{
    this->lives = 2;
    this->counter = 0;
    this->counter2=0;
    this->stopCounter = 0;
//    moveTimer = new QTimer();
//    connect(moveTimer , SIGNAL(timeout()) , this , SLOT(moveDown()));
//    moveTimer->start(50);
//    motionTimer = new QTimer();
//    connect(motionTimer , SIGNAL(timeout()) , this , SLOT(motionWings()));
//    motionTimer->start(90);

//    inPlaceMotionTimer = new QTimer();
//    connect(inPlaceMotionTimer , SIGNAL(timeout()) , this , SLOT(inPlaceMotion()));
//    inPlaceMotionTimer->start(200);
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

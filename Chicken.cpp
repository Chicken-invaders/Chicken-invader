#include "Chicken.h"

Chicken::Chicken(int row) : index (row)
{counter = 0;
counter2=0;
stopCounter = 0;
moveTimer = new QTimer();
connect(moveTimer , SIGNAL(timeout()) , this , SLOT(moveDown()));
moveTimer->start(50);
motionTimer = new QTimer();
connect(motionTimer , SIGNAL(timeout()) , this , SLOT(motionWings()));
motionTimer->start(90);

inPlaceMotionTimer = new QTimer();
connect(inPlaceMotionTimer , SIGNAL(timeout()) , this , SLOT(inPlaceMotion()));
inPlaceMotionTimer->start(200);
}

void Chicken::moveDown()
{
    moveBy(0 , (index+1) * 5);
    stopCounter++;
    if(stopCounter == 29){
          disconnect(moveTimer , SIGNAL(timeout()) , this , SLOT(moveDown()));

   }
}
void Chicken::motionWings()
{
    counter++;
    if(counter % 4 == 0)
    setPixmap(QPixmap(":/ images/chicken0.png"));
    else  if(counter % 4 == 1)
    setPixmap(QPixmap(":/ images/chicken1.png"));
    else  if(counter % 4 == 2)
    setPixmap(QPixmap(":/ images/chicken2.png"));
    else  if(counter % 4 == 3)
    setPixmap(QPixmap(":/ images/chicken1.png"));
}

void Chicken::inPlaceMotion()
{
    counter2++;
    if(counter2 % 2 == 0){
        moveBy(0 , -5);
    }
    else {
        moveBy(0 , 5);
    }
}


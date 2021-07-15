#include "Superhen.h"

Superhen::Superhen(int row) : Chicken(row)
{
    this->lives = 4;
    this->counter = 0;
    this->counter2=0;
    this->stopCounter = 0;
}

void Superhen::motionWings()
{
    counter++;
    if(counter % 4 == 0)
    setPixmap(QPixmap(":/ images/superhen0.png"));
    else  if(counter % 4 == 1)
    setPixmap(QPixmap(":/ images/superhen1.png"));
    else  if(counter % 4 == 2)
    setPixmap(QPixmap(":/ images/superhen2.png"));
    else  if(counter % 4 == 3)
        setPixmap(QPixmap(":/ images/superhen1.png"));
}



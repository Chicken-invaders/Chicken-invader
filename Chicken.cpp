#include "Chicken.h"

Chicken::Chicken(int row) : index (row)
{counter = 0;
counter2=0;}

void Chicken::moveDown()
{
    moveBy(0 , (index+1) * 5);
}

void Chicken::motionWings()
{
    counter++;
    if(counter % 4 == 0)
    setPixmap(QPixmap("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/chicken0.png"));
    else  if(counter % 4 == 1)
    setPixmap(QPixmap("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/chicken1.png"));
    else  if(counter % 4 == 2)
    setPixmap(QPixmap("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/chicken2.png"));
    else  if(counter % 4 == 3)
    setPixmap(QPixmap("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/chicken1.png"));
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


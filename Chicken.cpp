#include "Chicken.h"
#include "View.h"
extern View *v;
Chicken::Chicken(int row) : row (row) , lives(1)
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

Chicken::~Chicken()
{
}

void Chicken::generateEgg()
{
    egg=new Egg;
v->scene->addItem(egg);
 egg->setPos(this->x()+50,this->y()+90);
// egg->moveDown();

}

void Chicken::generateMeat()
{
        meat=new Meat;
        v->scene->addItem(meat);
        meat->setPos(this->x()+50,this->y()+90);
}
void Chicken::moveDown()
{if(v->pause==false)
    {
        moveBy(0 ,(row+1) * 5);
        stopCounter++;
        if(stopCounter == 30){
            disconnect(moveTimer , SIGNAL(timeout()) , this , SLOT(moveDown()));
        }
    }
}
void Chicken::motionWings()
{   if(v->pause==false)
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

}

void Chicken::inPlaceMotion()
{if(v->pause==false)
    {
        counter2++;
        if(counter2 % 2 == 0){
            moveBy(0 , -5);
        }
        else {
            moveBy(0 , 5);
        }
    }
}


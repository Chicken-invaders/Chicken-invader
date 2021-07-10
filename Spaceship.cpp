#include "Spaceship.h"

SpaceShip::SpaceShip()
{
   lives = new Lives();
   setPixmap(QPixmap(":/ images/spaceshipp.png"));
   setPos(910,800);
}

void SpaceShip::Collision()
{
    QList<QGraphicsItem *> collidingitems= collidingItems();
for(int i=0;i<collidingitems.size();i++){
    if(typeid (*(collidingitems[i]))==typeid (Chicken))
   {     delete collidingitems[i];
                   lives->decreaseLives();
    }
  }
}




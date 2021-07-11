#include "Spaceship.h"
#include "View.h"
extern View * v;
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
    if(typeid (*(collidingitems[i]))==typeid (Chicken)||typeid (*(collidingitems[i]))==typeid (Egg))
   {     delete collidingitems[i];
                   lives->decreaseLives();
                 v->score->increase(5);
    }
  }
}




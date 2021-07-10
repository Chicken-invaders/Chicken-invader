#include "Bullet.h"

Bullet::Bullet()
{
setPixmap(QPixmap("C:/Users/Hossein/Desktop/ap/Chicken-invader/bullet2.png"));
timer=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(moveUp()));
timer->start(50);


}

void Bullet::collision()
{
    QList<QGraphicsItem *> collidingitems= collidingItems();
for(int i=0;i<collidingitems.size();i++){
    if(typeid (*(collidingitems[i]))==typeid (Chicken))
   {     delete collidingitems[i];
        delete this;

    }

}
}



void Bullet::moveUp()
{
moveBy(0,-27);
collision();
}

#include "Bullet.h"

Bullet::Bullet()
{
setPixmap(QPixmap(":/ images/bullet2.png"));
timer=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(moveUp()));
timer->start(50);


}

QList<QGraphicsItem *> Bullet::collision()
{
    QList<QGraphicsItem *> collidingitems = collidingItems();
for(int i=0;i<collidingitems.size();i++){
    if(typeid (*(collidingitems[i]))==typeid (Chicken))
   {     delete [] collidingitems[i];
        delete this;
    }

}
return collidingitems;
}

void Bullet::moveUp()
{
moveBy(0,-27);
collision();
if(y() < 0){
    delete this;
}
}

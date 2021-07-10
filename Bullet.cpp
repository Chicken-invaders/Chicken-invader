#include "Bullet.h"

#include "View.h"

extern View * v;

Bullet::Bullet()
{
setPixmap(QPixmap(":/ images/bullet2.png"));
timer=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(moveUp()));
timer->start(50);


}

void Bullet::collision()
{
    QList<QGraphicsItem *> collidingitems = collidingItems();
for(int i=0;i<collidingitems.size();i++){
    if(typeid (*(collidingitems[i]))==typeid (Chicken))
    {
        delete collidingitems[i];
        collidingitems[i] = nullptr;
        v->score->increase(5);
        delete this;
    }
  }
}

void Bullet::moveUp()
{
moveBy(0,-27);
collision();
if(y() < 0){
    delete this;
}
}

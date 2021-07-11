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
    if(typeid (*(collidingitems[i]))==typeid (Chicken) || typeid (*(collidingitems[i]))==typeid (Hen))
    {
        for(int j=0;j<v->chickens.size();j++){
            if(collidingitems[i]==dynamic_cast<QGraphicsItem*>(v->chickens[j]))
            {
                v->score->increase(5);
                v->chickens[j]->lives--;
                if( v->chickens[j]->lives == 0){
                v->chickens.remove(j);
                delete collidingitems[i];
                }
                break;
            }
        }
        delete this;
       }
    else if (typeid (*(collidingitems[i]))==typeid (Egg)){
        v->score->increase(5);
        delete collidingitems[i];
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

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

                v->chickens[j]->lives--;
                if( v->chickens[j]->lives == 0){
                    if(typeid (*(collidingitems[i]))==typeid (Chicken))
                    v->score->increase(5);
                    else v->score->increase(10);

                    //if object is Hen generate meat
                    if(typeid (*(collidingitems[i]))==typeid (Hen))
                    v->meat->generateMeat(v->chickens[j]->x()+50,v->chickens[j]->y()+40);
                    v->chickens.remove(j);
                    delete collidingitems[i];
                }delete this;
               return;
            }
          }
        }
       else if(typeid (*(collidingitems[i]))==typeid (Egg)){
           v->score->increase(5);
           delete collidingitems[i];
           delete this;
           return;
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

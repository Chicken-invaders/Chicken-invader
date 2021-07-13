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
       if(typeid (*(collidingitems[i]))==typeid (Chicken) || typeid (*(collidingitems[i]))==typeid (Hen) || typeid (*(collidingitems[i]))==typeid (Superhen))
       {
        for(int j=0;j<v->chickens.size();j++){
            if(collidingitems[i]==dynamic_cast<QGraphicsItem*>(v->chickens[j]))
            {

                v->chickens[j]->lives--;
                if( v->chickens[j]->lives == 0){
                    // add 5 score for chicken and add 10 score for hen and 20 score for super hen
                    if(typeid (*(collidingitems[i]))==typeid (Chicken))
                    v->score->increase(5);
                    else if(typeid (*(collidingitems[i]))==typeid (Hen))
                    v->score->increase(10);
                    else
                    v->score->increase(20);

                    //if object is Hen or super hen generate meat
                    if(typeid (*(collidingitems[i]))==typeid (Hen) || typeid (*(collidingitems[i]))==typeid (Superhen))
                    v->meat->generateMeat(v->chickens[j]->x()+50,v->chickens[j]->y()+40);

                    //delete object
                     delete collidingitems[i];
                    //remove hen or chicken from vector
                    v->chickens.remove(j);
              if(v->chickens.size() == 0){
              v->endLevelSecond = v->sec;
               }
             }
                // delete bullet
                delete this;
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
if(y() < 4){
    delete this;
}
}

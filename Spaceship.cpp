#include "Spaceship.h"
#include "View.h"
extern View * v;
SpaceShip::SpaceShip()
{
   lives = new Lives();
   setPixmap(QPixmap(":/ images/spaceshipp.png"));
   setPos(910,800);
   timer = new QTimer();
   connect(timer , SIGNAL(timeout()) , this , SLOT(Collision()));
   timer->start(20);
}

void SpaceShip::Collision()
{
    QList<QGraphicsItem *> collidingitems= collidingItems();
for(int i=0;i<collidingitems.size();i++){
    if(typeid (*(collidingitems[i]))==typeid (Chicken))
    {//check whether the spaceship has collision with chickens or eggs
        for(int j=0;j<v->chickens.size();j++){
            if(collidingitems[i]==dynamic_cast<QGraphicsItem*>(v->chickens[j]))
            {
                delete collidingitems[i];
                v->chickens.remove(j);
                explo = new Explosion();
                v->scene->addItem(explo);
                explo->setPos(this->x() , this->y() - 50);
                lives->decreaseLives();
                v->score->increase(5);
                if(v->chickens.size() == 0){
                    v->endLevelSecond = v->sec;
                  }
               return;
             }
        }
    }
    else if( typeid (*(collidingitems[i]))==typeid (Egg)){
        delete collidingitems[i];
        explo = new Explosion();
        v->scene->addItem(explo);
        explo->setPos(this->x() , this->y() - 50);
        lives->decreaseLives();
       return;
    }
   else if(typeid (*(collidingitems[i]))==typeid (Hen)){
        for(int j=0;j<v->chickens.size();j++){
            if(collidingitems[i]==dynamic_cast<QGraphicsItem*>(v->chickens[j]))
            {
                delete collidingitems[i];
                v->chickens.remove(j);
                explo = new Explosion();
                v->scene->addItem(explo);
                explo->setPos(this->x() , this->y() - 50);
                lives->decreaseLives();
                v->score->increase(10);
                if(v->chickens.size() == 0){
                    v->endLevelSecond = v->sec;
                  }
               return;
             }
    }
    }
    else if(typeid (*(collidingitems[i]))==typeid (Superhen)){
         for(int j=0;j<v->chickens.size();j++){
             if(collidingitems[i]==dynamic_cast<QGraphicsItem*>(v->chickens[j]))
             {
                 delete collidingitems[i];
                 v->chickens.remove(j);
                 explo = new Explosion();
                 v->scene->addItem(explo);
                 explo->setPos(this->x() , this->y() - 50);
                 lives->decreaseLives();
                 v->score->increase(20);
                 if(v->chickens.size() == 0){
                     v->endLevelSecond = v->sec;
                   }
                return;
              }
             }
     }else if(typeid (*(collidingitems[i]))==typeid (Meat)){
        delete collidingitems[i];//check whether the spaceship has recevied the meat or not
        v->nom->increase(1);

    }else if(typeid (*(collidingitems[i]))==typeid (Gift)){
        delete collidingitems[i];//check whether the spaceship has recevied the gift or not
        v->isGifted=true;
    return;
  }
}
}



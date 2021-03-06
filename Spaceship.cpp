#include "Spaceship.h"
#include "View.h"
extern View * v;
SpaceShip::SpaceShip(int live)
{
   lives = new Lives(live);
   setPixmap(QPixmap(":/ images/spaceshipp.png"));
   setPos(910,800);
   timer = new QTimer();
   connect(timer , SIGNAL(timeout()) , this , SLOT(Collision()));
   timer->start(20);
}

SpaceShip::~SpaceShip()
{
    delete explo;
    delete bullet;
    delete timer;
}

void SpaceShip::Collision()
{
    QList<QGraphicsItem *> collidingitems= collidingItems();
for(int i=0;i<collidingitems.size();i++){
    if(typeid (*(collidingitems[i]))==typeid (Chicken))
    {
        //check whether the spaceship has collision with chickens
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
    else if( typeid (*(collidingitems[i]))==typeid (Egg)){//check whether the spaceship has collision with eggs
        delete collidingitems[i];
        explo = new Explosion();
        v->scene->addItem(explo);
        explo->setPos(this->x() , this->y() - 50);
        lives->decreaseLives();
       return;
    }
   else if(typeid (*(collidingitems[i]))==typeid (Hen)){//check whether the spaceship has collision with hens
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
    else if(typeid (*(collidingitems[i]))==typeid (Superhen)){//check whether the spaceship has collision with superhens

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
        if(v->nom->scores==30 && v->currentLevel>2)
        {

            v->score->increase(50);
            v->nom->reset();

        }
    }else if(typeid (*(collidingitems[i]))==typeid (Gift)){
        delete collidingitems[i];//check whether the spaceship has recevied the gift or not
        v->isGifted=true;
        return;
  }
}
}



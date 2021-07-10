#include "Bullet.h"

Bullet::Bullet()
{
setPixmap(QPixmap("C:/Users/Hossein/Desktop/ap/Chicken-invader/bullet2.png"));
timer=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(moveUp()));
timer->start(50);


}



void Bullet::moveUp()
{
moveBy(0,-27);

}

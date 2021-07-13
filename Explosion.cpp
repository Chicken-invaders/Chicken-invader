#include "Explosion.h"

Explosion::Explosion(): counter(0)
{
    timer = new QTimer();
    connect(timer , SIGNAL(timeout()) , this , SLOT(exploAnimation()));
    timer->start(80);
}

void Explosion::exploAnimation()
{
    if(counter == 0)
    setPixmap(QPixmap(":/ images/boom0.png"));
    else if(counter == 1)
        setPixmap(QPixmap(":/ images/boom1.png"));
    else if(counter  == 2)
        setPixmap(QPixmap(":/ images/boom2.png"));
    else if (counter == 10){
        delete this;
    }
    counter ++;
}

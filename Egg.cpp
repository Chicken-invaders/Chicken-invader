#include "Egg.h"
#include "View.h"
extern View * v;
Egg::Egg()
{
    setPixmap(QPixmap(":/ images/egg2.png"));
timer=new QTimer();
connect(timer , SIGNAL(timeout()) , this , SLOT(moveDown()));
timer->start(50);
//generateEgg();

}

//void Egg::generateEgg()
//{ int rvalue;
//    QRandomGenerator *gen6 = QRandomGenerator::system();
//       rvalue=gen6->bounded(20);

//       setPos(v->chickens[rvalue]->x()+50,v->chickens[rvalue]->y()+90);
//}

void Egg::moveDown()
{
    moveBy(0,+27);
if(y()>1080)
    delete this;
}

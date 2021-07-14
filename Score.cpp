#include "Score.h"
#include <QString>
#include <QFont>
#include "View.h"
extern View* v;
Score::Score() :QGraphicsTextItem() , scores(0)
{
setPlainText(QString::number(scores));
setDefaultTextColor("white");
setFont(QFont("timer" , 20));
//setPlainText(QString::number(numberOfMeat));
//QTimer *timer=new QTimer();
//connect(timer , SIGNAL(timeout()) , this , SLOT(checker()));
//timer->start(50);
}
void Score::increase(int s)
{
    scores+=s;
    setPlainText(QString::number(scores));
}

void Score::reset()
{
    scores=0;
     setPlainText(QString::number(scores));
}

//void Score::increaseMeat(int m)
//{
//    numberOfMeat +=m;
//    setPlainText(QString::number(numberOfMeat));
//}

//void Score::resetNumberOfMeat()
//{
//    numberOfMeat=0;
//    setPlainText(QString::number(numberOfMeat));
//}

//void Score::checker()
//{
//if(numberOfMeat==5){
//    resetNumberOfMeat();
//    v->score->increase(10);
//}
//}

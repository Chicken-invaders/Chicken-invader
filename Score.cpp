#include "Score.h"
#include <QString>
#include <QFont>
#include "View.h"
extern View* v;


Score::Score(int score) :QGraphicsTextItem() , scores(score)
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



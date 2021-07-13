#include "Lives.h"
#include <QFont>
#include "View.h"
extern View * v;
Lives::Lives() :  QGraphicsTextItem()  , lives(3)
{
       setPlainText(QString::number(lives));
       setDefaultTextColor("white");
       setFont(QFont("timer" , 20));
}

void Lives::decreaseLives()
{
    lives--;
    setPlainText(QString::number(lives));
    if(lives == 0){
        v->endLevelSecond = v->sec;
    }
}

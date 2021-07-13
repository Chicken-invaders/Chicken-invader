#include "Lives.h"
#include <QFont>
Lives::Lives() :  QGraphicsTextItem()  , lives(50)
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
        exit(1);
    }

}

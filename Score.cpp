#include "Score.h"
#include <QString>
#include <QFont>

Score::Score() : QGraphicsTextItem() , scores(0)
{
setPlainText(QString::number(scores));
setDefaultTextColor("white");
setFont(QFont("timer" , 20));
}
void Score::increase(int s)
{
    scores+=s;
    setPlainText(QString::number(scores));
}

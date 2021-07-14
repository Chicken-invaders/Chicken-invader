#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QTimer>


class Score :public QGraphicsTextItem
{
    Q_OBJECT
private:

public:
    int scores;
//    int numberOfMeat;
    Score();
    void increase(int s);
    void increaseMeat(int m);
    void resetNumberOfMeat();
    void reset();
//public slots:
//    void checker();
};

#endif // SCORE_H

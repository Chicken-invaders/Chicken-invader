#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QTimer>
#include "Pausemenu.h"

#include "Spaceship.h"

class Score :public QGraphicsTextItem
{
    Q_OBJECT

private:



public:

//funtions
    Score(int score);
    void increase(int s);
    void reset();
    int scores;


};

#endif // SCORE_H

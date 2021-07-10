#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
private:

public:
    int scores;
    Score();
    void increase(int s);

};

#endif // SCORE_H

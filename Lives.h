#ifndef LIVES_H
#define LIVES_H
#include <QGraphicsTextItem>
class Lives : public QGraphicsTextItem
{

public:
    int lives;
    Lives();
    void decreaseLives();
};

#endif // LIVES_H

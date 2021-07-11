#ifndef CHICKEN_H
#define CHICKEN_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Egg.h"
class Chicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int lives;
    int row;
    int counter;
    int counter2;
    int stopCounter;
    QTimer * moveTimer;
    QTimer * motionTimer;
    QTimer * inPlaceMotionTimer;
    Egg * egg;
    QTimer *eggtime;


public:
    Chicken(int row);
 void generateEgg();

public slots:
    void moveDown();
    void motionWings();
    void inPlaceMotion();
};

#endif // CHICKEN_H

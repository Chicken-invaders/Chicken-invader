#ifndef CHICKEN_H
#define CHICKEN_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Egg.h"
#include "Meat.h"



class Chicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    friend class Bullet;
    friend class View;
    protected:
    int lives;
    int row;
    int counter;
    int counter2;
    int stopCounter;
    QTimer * moveTimer;
    QTimer * motionTimer;
    QTimer * inPlaceMotionTimer;
    QTimer *eggtime;
    Egg * egg; 
    Meat * meat;


public:
    Chicken(int row);
    ~Chicken();
    void generateEgg();
    void generateMeat();

public slots:
    virtual void moveDown();
    virtual void motionWings();
    virtual void inPlaceMotion();
};

#endif // CHICKEN_H

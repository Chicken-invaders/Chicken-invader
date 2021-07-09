#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "Bullet.h"
#include "QMouseEvent"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QCursor>
#include <QGraphicsView>

class SpaceShip: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int lives;
    Bullet* bullet;


public:
    SpaceShip();


};

#endif // SPACESHIP_H

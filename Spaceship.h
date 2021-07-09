#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "Bullet.h"
#include "QMouseEvent"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QCursor>
#include <QGraphicsView>
#include <Chicken.h>
#include <QTimer>
#include <QMessageBox>

class SpaceShip: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int lives=3;
    Bullet* bullet;
    QTimer * timer;

public:
    SpaceShip();
public slots:
    void Collision();


};

#endif // SPACESHIP_H

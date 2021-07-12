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
#include "Lives.h"
#include "Meat.h"
#include "Gift.h"
class SpaceShip: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:

    Bullet* bullet;
    QTimer * timer;



public: Lives * lives;
    SpaceShip();
public slots:
    void Collision();


};

#endif // SPACESHIP_H

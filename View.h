#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include "Chicken.h"
#include "Spaceship.h"
#include <QCursor>
#include <QMediaPlayer>
#include "Bullet.h"
#include <QKeyEvent>

class View : public QGraphicsView
{
    Q_OBJECT
private:

    QGraphicsScene * scene;
    QGraphicsRectItem * rectItem;
    QGraphicsPixmapItem * scoreBoard;
    QGraphicsPixmapItem * heartIcon;
    QGraphicsPixmapItem * heartBack;
    QTimer * moveTimer;
    QTimer * motionTimer;
    QTimer * inPlaceMotionTimer;
    QVector <Chicken *> chickens;
    SpaceShip * spaceship;
    Bullet * bullet;

public:
    explicit View();
     ~View();
     void addChicken(int index);
       void mouseMoveEvent(QMouseEvent * event);
       void addBullet();
       void keyPressEvent(QKeyEvent *);

public slots:
//void viewMove();
//void viewMotion();
//void inPlaceMotion();

signals:

};

#endif // VIEW_H

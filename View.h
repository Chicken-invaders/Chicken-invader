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
#include "Score.h"
#include <QKeyEvent>
#include "Egg.h"


class View : public QGraphicsView
{

    Q_OBJECT
private:
    friend class Bullet;
    friend class SpaceShip;
    friend class Egg;
    QTimer * vtimer;
    bool flag;
    int sec;
    QGraphicsScene * scene;
    QGraphicsRectItem * rectItem;
    QGraphicsPixmapItem * scoreBoard;
    QGraphicsPixmapItem * heartIcon;
    QGraphicsPixmapItem * heartBack;
    QVector <Chicken *> chickens;
    SpaceShip * spaceship;
    Bullet * bullet;
    Score * score;
    Egg * egg;




public: QList<QGraphicsItem *> deltedObjects;
      int level;
      explicit View();
       ~View();
       void addChicken(int index);
       void mouseMoveEvent(QMouseEvent * event);
       void addBullet();
       void addSpaceShip();
       void keyPressEvent(QKeyEvent *);

public slots:
void schedule();

};

#endif // VIEW_H

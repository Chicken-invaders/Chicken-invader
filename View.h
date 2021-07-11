#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include "Hen.h"
#include "Spaceship.h"
#include <QCursor>
#include <QMediaPlayer>
#include "Bullet.h"
#include "Score.h"
#include <QKeyEvent>
#include <QRandomGenerator64>
#include "Egg.h"
#include "Meat.h"


class View : public QGraphicsView
{

    Q_OBJECT
private:
    friend class Bullet;
    friend class SpaceShip;
    friend class Egg;
    friend class Chicken;
    friend class Meat;
    QTimer * vtimer;
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
    Meat* meat;
    int rvalue;
    int row;
    int col;
    int pos_x;
    int endLevelSecond;
    int currentLevel;




       public:
       QList<QGraphicsItem *> deltedObjects;
       explicit View();
       ~View();
       void addChicken(int index);
       void mouseMoveEvent(QMouseEvent * event);
       void addBullet();
       void addSpaceShip();
       void keyPressEvent(QKeyEvent *);
       void level_1();
       void level_2();
       void level_3();
       void level_4();


public slots:
void schedule();

};

#endif // VIEW_H

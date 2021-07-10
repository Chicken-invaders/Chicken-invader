#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <Chicken.h>


class Bullet:  public QObject , public QGraphicsPixmapItem
{
   Q_OBJECT
public:

    Bullet();

    QTimer* timer;
    QList<QGraphicsItem *> collision();

 public slots:
    void moveUp();

};

#endif // BULLET_H

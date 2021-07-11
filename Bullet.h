#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <Chicken.h>
#include <QList>


class Bullet:  public QObject , public QGraphicsPixmapItem
{
   Q_OBJECT
    public:
    Bullet();
    QTimer* timer;
    void collision();

 public slots:
    void moveUp();

};

#endif // BULLET_H

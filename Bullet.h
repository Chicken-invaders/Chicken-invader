#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bullet:  public QObject , public QGraphicsPixmapItem
{
   Q_OBJECT
public:

    Bullet();

    QTimer* timer;

 public slots:
    void moveUp();

};

#endif // BULLET_H

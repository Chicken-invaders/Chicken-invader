#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>


class Bullet:  public QObject , public QGraphicsPixmapItem
{

   Q_OBJECT
    private:
    QTimer* timer;// timer to move up the bullets
    public:
    Bullet();
    ~Bullet();
    void collision();

 public slots:
    void moveUp();

};

#endif // BULLET_H

#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Explosion :  public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Explosion();
    QTimer *timer;
    int counter;

public slots:
    void exploAnimation();
};

#endif // EXPLOSION_H

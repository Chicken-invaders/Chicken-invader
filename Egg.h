#ifndef EGG_H
#define EGG_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QRandomGenerator64>
class Egg: public QObject , public QGraphicsPixmapItem
{
Q_OBJECT

private:
    QTimer *timer;
public:
    Egg();
    ~Egg();


public slots:
    void moveDown();

};

#endif // EGG_H

#ifndef CHICKEN_H
#define CHICKEN_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
class Chicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QTimer *timer;
    int lives;
    int index;
    int counter;
    int counter2;

public:
    Chicken(int row);
    void moveDown();
    void motionWings();
    void inPlaceMotion();
};

#endif // CHICKEN_H

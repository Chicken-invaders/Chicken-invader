#ifndef CHICKEN_H
#define CHICKEN_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
class Chicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int lives;
    int row;
    int counter;
    int counter2;
    int stopCounter;
    QTimer * moveTimer;
    QTimer * motionTimer;
    QTimer * inPlaceMotionTimer;

public:
    Chicken(int row);

public slots:
    void moveDown();
    void motionWings();
    void inPlaceMotion();
};

#endif // CHICKEN_H

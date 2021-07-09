#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include "Chicken.h"
class View : public QGraphicsView
{
    Q_OBJECT
private:

    QGraphicsScene * scene;
    QGraphicsRectItem * rectItem;
    QGraphicsPixmapItem * scoreBoard;
    QGraphicsPixmapItem * heartIcon;
    QGraphicsPixmapItem * heartBack;
    QTimer * moveTimer;
    QTimer * motionTimer;
    QTimer * inPlaceMotionTimer;
    QVector <Chicken *> chickens;
public:
    explicit View();
     ~View();
     void addChicken(int index);
public slots:
void viewMove();
void viewMotion();
void inPlaceMotion();

signals:

};

#endif // VIEW_H

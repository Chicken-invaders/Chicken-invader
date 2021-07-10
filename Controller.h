#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QTimer>
#include <QGraphicsView>
#include "Chicken.h"
#include "View.h"

class Controller : QGraphicsView
{
    Q_OBJECT
private:
    int level;
public:
    View * v;
    QTimer * timer;
     Controller();
    ~Controller();
public slots:
     void add();
};

#endif // CONTROLLER_H

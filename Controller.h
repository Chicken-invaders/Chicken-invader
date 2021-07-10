#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QTimer>
#include "Chicken.h"

class Controller : public QObject
{
    Q_OBJECT
private:

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

};

#endif // CONTROLLER_H

#ifndef MEAT_H
#define MEAT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Meat : public QObject , public QGraphicsPixmapItem
{
Q_OBJECT
private:
    QTimer* timer;
public:
    Meat();

public slots:
    void moveDown();
};

#endif // MEAT_H

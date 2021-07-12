#ifndef GIFT_H
#define GIFT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>


class Gift:public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer *timer;
public:
    Gift();
public slots:
    void moveDown();
};

#endif // GIFT_H

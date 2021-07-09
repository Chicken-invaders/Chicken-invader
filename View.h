#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
class View : public QGraphicsView
{
    Q_OBJECT
private:
     QGraphicsScene * scene;
     QTimer * viewTimer;
public:
    explicit View();

signals:

};

#endif // VIEW_H

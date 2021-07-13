#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsPixmapItem>




class Menu :public QGraphicsView,public QGraphicsPixmapItem
{Q_OBJECT
private:
    QGraphicsScene * mscene;
    QPushButton * newGameButton;
public:
    Menu();
};

#endif // MENU_H

#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include "View.h"
#include <QPixmap>
#include <QIcon>



class Menu :public QGraphicsView
{           Q_OBJECT
    private:
    QTimer * timer;
    QGraphicsScene * scene;
    QPushButton * newGameButton;
    QPushButton * quitButton;
    QPushButton * cridtButton;
    QPushButton * loadButton;
    public:
    Menu();

 public slots:
       void playNewGame();
       void exitGame();
       void load();
       void checkEnd();
};

#endif // MENU_H

#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include <QObject>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include "View.h"
#include <QPixmap>
#include <QKeyEvent>

class PauseMenu:public QGraphicsView
{   Q_OBJECT
private:
     QGraphicsScene * scene;
     QPushButton* save;
     QPushButton* Resume;
     QPushButton* menu;
public:

    PauseMenu();
     void keyPressEvent(QKeyEvent *);
};

#endif // PAUSEMENU_H

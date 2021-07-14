#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include <QObject>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsPixmapItem>

#include <QPixmap>
#include <QKeyEvent>

class PauseMenu:public QGraphicsView
{    Q_OBJECT
private:
     QGraphicsScene * scene;
     QPushButton* save;
     QPushButton* Resume;
     QPushButton* menu;
public:

     PauseMenu();
    ~PauseMenu();
     void keyPressEvent(QKeyEvent *);//ESC for pause the game
public slots :
     void goToMenu();
     void resumeF();
     void saveF();
};

#endif // PAUSEMENU_H

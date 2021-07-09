#include "View.h"

View::View() : QGraphicsView()
{
    //create scene
scene = new QGraphicsScene();
scene->setSceneRect(0,0,1920,1080);
setScene(scene);

   //set background
setBackgroundBrush(QBrush(QImage("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/background.jpg")));

//fix size
setFixedSize(1920,1080);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

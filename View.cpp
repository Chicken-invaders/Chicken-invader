#include "View.h"
#include "QThread"
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
for (int i = 0 ; i < 20 ; i++ ) {
    addChicken(i);
}
moveTimer = new QTimer();
connect(moveTimer , SIGNAL(timeout()) , this , SLOT(viewMove()));
moveTimer->start(50);
motionTimer = new QTimer();
connect(motionTimer , SIGNAL(timeout()) , this , SLOT(viewMotion()));
motionTimer->start(80);
inPlaceMotionTimer = new QTimer();
connect(inPlaceMotionTimer , SIGNAL(timeout()) , this , SLOT(inPlaceMotion()));
inPlaceMotionTimer->start(100);
}

View::~View()
{}

void View::viewMove()
{
    for (int i = 0 ; i < 20 ; i++ ) {
          if(chickens[19]->y() < 500)
        chickens[i]->moveDown();
    }
}

void View::viewMotion()
{
    for (int i = 0 ; i < 20 ; i++ ) {
        chickens[i]->motionWings();
    }
}

void View::inPlaceMotion()
{
    for (int i = 0 ; i < 20 ; i++ ) {
          chickens[i]->inPlaceMotion();
    }
}

void View::addChicken(int index)
{
   chickens.push_back(new Chicken((index / 5)));
   scene->addItem(chickens.last());
   chickens.last()->setPos(610 + (index % 5)*150 ,-90);
}

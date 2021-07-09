#include "View.h"
#include "QThread"
View::View() : QGraphicsView()
{
//create scene
scene = new QGraphicsScene();
scene->setSceneRect(0,0,1920,1080);
setScene(scene);

setWindowFlags(Qt::Window|Qt::FramelessWindowHint);

//set background
setBackgroundBrush(QBrush(QImage("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/background.jpg")));

//set score board
scoreBoard=new QGraphicsPixmapItem();
scoreBoard->setPixmap(QPixmap("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/scoreboard.png"));
scene->addItem(scoreBoard);
scoreBoard->setPos(2,2);
//set heart background
heartBack=new QGraphicsPixmapItem();
heartBack->setPixmap(QPixmap("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/heartback.png"));
scene->addItem(heartBack);
heartBack->setPos(2,1030);
//set heart icon
heartIcon=new QGraphicsPixmapItem();
heartIcon->setPixmap(QPixmap("C:/Users/AmirHMN/Desktop/Chicken-Invader/Chicken-Invaders/heart.png"));
scene->addItem(heartIcon);
heartIcon->setPos(150,1030);
//fix size
setFixedSize(1920,1080);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
for (int i = 0 ; i < 20 ; i++ ) {
    addChicken(i);
}
}

View::~View()
{}

//void View::viewMove()
//{
//    for (int i = 0 ; i < 20 ; i++ ) {
//          if(chickens[19]->y() < 500)
//        chickens[i]->moveDown();
//    }
//}

//void View::viewMotion()
//{
//    for (int i = 0 ; i < 20 ; i++ ) {
//        chickens[i]->motionWings();
//    }
//}

//void View::inPlaceMotion()
//{
//    qrand();
//    for (int i = 0 ; i < 20 ; i++ ) {
//          chickens[i]->inPlaceMotion();
//    }
//}

void View::addChicken(int index)
{
   chickens.push_back(new Chicken((index / 5)));
   scene->addItem(chickens.last());
   chickens.last()->setPos(610 + (index % 5)*150 ,-90);
}

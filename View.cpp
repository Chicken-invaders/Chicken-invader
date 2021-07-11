#include "View.h"
#include "QThread"
#include "QDebug"
View::View() : QGraphicsView() , sec(0) , level(1) , flag(true)
{
    QCursor cursor(Qt::BlankCursor);
        setCursor(cursor);
    setMouseTracking(true);
    setFocus();
//create scene
scene = new QGraphicsScene();
scene->setSceneRect(0,0,1920,1080);
setScene(scene);

setWindowFlags(Qt::Window|Qt::FramelessWindowHint);

//set background
setBackgroundBrush(QBrush(QImage(":/ images/background.jpg")));



//set score board
scoreBoard=new QGraphicsPixmapItem();
scoreBoard->setPixmap(QPixmap(":/ images/scoreboard.png"));
scene->addItem(scoreBoard);
scoreBoard->setPos(2,2);


//set heart background
heartBack=new QGraphicsPixmapItem();
heartBack->setPixmap(QPixmap(":/ images/heartback.png"));
scene->addItem(heartBack);
heartBack->setPos(2,1030);


//set heart icon
heartIcon=new QGraphicsPixmapItem();
heartIcon->setPixmap(QPixmap(":/ images/heart.png"));
scene->addItem(heartIcon);
heartIcon->setPos(150,1035);


//fix size
setFixedSize(1920,1080);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//set score
vtimer = new QTimer();
connect(vtimer , SIGNAL(timeout()) , this , SLOT(schedule()));
vtimer->start(1000);

addSpaceShip();

scene->addItem(spaceship->lives);
spaceship->lives->setPos(110,1033);
//music
auto musicPlayer =new QMediaPlayer();
musicPlayer->setMedia(QUrl("qrc:/music/02-04. Main Theme (Remastered)"));
musicPlayer->play();


//score part
 score = new Score();
 scene->addItem(score);
 score->setPos(50 ,2);
 //egg part




}

View::~View()
{

}


void View::addChicken(int index)
{
    int col;
    int pos_x;
    if(level == 1){
        col =5;
    }else if(level == 2){
        col = 9;
    }
    pos_x =960 - ((col/2) * 150 + 50);
    for(int i = 0 ; i < index ; i++){
   chickens.push_back(new Chicken((i / col)));
   scene->addItem(chickens.last());
   chickens.last()->setPos(pos_x + (i % col)*150 ,-90);
    }
}
void View::mouseMoveEvent(QMouseEvent * event)
{
 spaceship->setPos(event->x() -50,event->y()-50);
 spaceship->Collision();


}

void View::addSpaceShip()
{
    spaceship=new SpaceShip();
    scene->addItem(spaceship);
}

void View::keyPressEvent(QKeyEvent* click)
{
    if(click->key()==Qt::Key_Space)
    {
        bullet=new Bullet();
        scene->addItem(bullet);
        bullet->setPos(spaceship->x()+36,spaceship->y()-36);

    }

}

void View::schedule()
{
    sec ++;
   if((sec == 4 || level == 2) && flag){

       if(level == 1)
       addChicken(20);
       else if (level == 2){
       addChicken(36);

       flag = false;
       }
   }
   if(chickens.size()==0&& sec>4){
       level = 2;
   }
   if(sec %5==0 && level==1)
   {
for(int i =0;i<chickens.size()/4;i++){


           QRandomGenerator *gen6 = QRandomGenerator::system();
              rvalue=gen6->bounded(chickens.size());

              chickens[rvalue]->generateEgg();
}

   }
}

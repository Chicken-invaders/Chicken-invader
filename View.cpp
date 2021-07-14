#include "View.h"
#include "QThread"
#include "QDebug"
PauseMenu * p;
View::View( int currentLevel , int inputLives , int inputScores , int inputMeats) :
    currentLevel(currentLevel) , inputLives(inputLives) , inputScores(inputScores) , inputMeats(inputMeats),
    QGraphicsView() , isGifted(false) , giftSecSaver(0) , lose(false), sec(0) , endLevelSecond(0)
{

// set cursor invisible
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

//connect schedule slot to timer (run severy 1 sec)
vtimer = new QTimer();
connect(vtimer , SIGNAL(timeout()) , this , SLOT(schedule()));
vtimer->start(1000);

// add spaceship
addSpaceShip();
scene->addItem(spaceship->lives);
spaceship->lives->setPos(110,1033);

//music
auto musicPlayer =new QMediaPlayer();
musicPlayer->setMedia(QUrl("qrc:/music/02-04. Main Theme (Remastered)"));
musicPlayer->play();


//score part
score = new Score(inputScores);
scene->addItem(score);
score->setPos(50 ,2);

levelstext = new QGraphicsTextItem();
levelstext->setDefaultTextColor("white");
levelstext->setFont(QFont("timer" , 50));
scene->addItem(levelstext);
levelstext->setPos(650 , 450);

//meat section
meatIcon=new QGraphicsPixmapItem();
meatIcon->setPixmap(QPixmap(":/ images/meaticon.png"));
scene->addItem(meatIcon);
meatIcon->setPos(60 ,1035);
nom=new Score(inputMeats);
scene->addItem(nom);
nom->setPos(20 ,1032);
}

View::~View()
{

}


void View::addChicken(int numberOfChickens)
{
    // add type of chickens based on their types
   for(int i = 0 ; i < numberOfChickens ; i++){
       if(currentLevel < 3){
          chickens.push_back(new Chicken((i / col)));
       }
       else if (currentLevel < 5){
           if(i % 2 == 0)
          chickens.push_back(new Chicken((i / col)));
          else
          chickens.push_back(new Hen((i / col)));
       }else{
           if(i % 2 == 0)
          chickens.push_back(new Hen((i / col)));
          else
          chickens.push_back(new Superhen((i / col)));
       }

       // add chickens one by one to the scene
   scene->addItem(chickens.last());
   chickens.last()->setPos(pos_x + (i % col)*140 ,-90);
   }
}

//link spaceship movment to the cursor
void View::mouseMoveEvent(QMouseEvent * event)
{if( !lose&& pause==false)
 spaceship->setPos(event->x() -50,event->y()-50);

}

void View::addSpaceShip()
{
    spaceship=new SpaceShip(inputLives);
    scene->addItem(spaceship);
}


//link shooting bullet to space key
void View::keyPressEvent(QKeyEvent* click)
{
    if(click->key()==Qt::Key_Space && !lose && pause==false)
    {if(isGifted == false ){
            bullet=new Bullet();
            scene->addItem(bullet);
            bullet->setPos(spaceship->x()+36,spaceship->y()-36);
        }else if(isGifted==true)
        {
                bullet2=new Bullet();
                scene->addItem(bullet2);
                bullet2->setPos(spaceship->x()+56,spaceship->y());
                bullet=new Bullet();
                scene->addItem(bullet);
                bullet->setPos(spaceship->x()+10,spaceship->y());
    }
  }if(click->key()==Qt::Key_1){
        p=new PauseMenu;
        p->show();
        pause=true;
    }
}

void View::level_1()
{
    row = 4;
    col = 5;
    pos_x =960 - ((col/2) * 140 + 50);
    addChicken(row * col);
}

void View::level_2()
{
    row = 4;
    col = 9;
    pos_x =960 - ((col/2) * 140 + 50);
     addChicken(row * col);
}

void View::level_3()
{
    row = 3;
    col = 8;
    pos_x =960 - ((col/2 - 1) * 140 + 120);
    addChicken(row * col);
}

void View::level_4()
{
    row = 3;
    col = 10;
    pos_x =960 - ((col/2 - 1) * 140 + 120);
    addChicken(row * col);
}

void View::level_5()
{
    row = 3;
    col = 6;
    pos_x =960 - ((col/2 - 1) * 140 + 120);
    addChicken(row * col);
}

void View::level_6()
{
    row = 3;
    col = 9;
    pos_x =960 - ((col/2 - 1) * 140 + 120);
    addChicken(row * col);
}

void View::schedule()
{
    sec ++;
    if(currentLevel == 0 && sec == 1){
        setLevelsText("Season 1 - Level 1:");
    }
   if(currentLevel == 0 && sec == 4){
         setLevelsText("");
         level_1();
         currentLevel = 1;
   }else if(currentLevel == 1 && chickens.size() == 0){
         setLevelsText("Season 1 - Level 2:");
   if(sec == endLevelSecond+4){
         setLevelsText("");
         currentLevel = 2;
         level_2();
     }
   }
   else if(currentLevel == 2 && chickens.size() == 0){
             setLevelsText("Season 2 - Level 1:");
        //from this stage we can have meat!
       if(sec == endLevelSecond+4){
             setLevelsText("");
             currentLevel = 3;
             level_3();

       }
   }
   else if(currentLevel == 3 && chickens.size() == 0){
       setLevelsText("Season 2 - Level 2:");
       if(sec == endLevelSecond+4){
             setLevelsText("");
             currentLevel = 4;
             level_4();
       }
   }
   else if(currentLevel == 4 && chickens.size() == 0){
       setLevelsText("Season 3 - Level 1:");
if(sec == endLevelSecond+4){

      setLevelsText("");
       currentLevel = 5;
       level_5();
       giftSecSaver=sec;
}

  }
   else if(currentLevel == 5 && chickens.size() == 0){
       setLevelsText("Season 3 - Level 2:");
       if(sec == endLevelSecond+4){
          setLevelsText("");
          currentLevel = 6;
          level_6();
          isGifted=false;
          giftSecSaver=sec;
       }
     }

   if(sec % 5 == 0)
   randomGenerateEgg();

   if(sec-giftSecSaver==15 && currentLevel > 4){
       //generation random pix.x() for the postion of the gift
        QRandomGenerator *gen5 = QRandomGenerator::system();
        int random=gen5->bounded(30,1900);
        gift=new Gift();
        scene->addItem(gift);
        gift->setPos(random,0);
   }

//qDebug()<<nom->scores;
}

void View::setLevelsText(QString string)
{

    levelstext->setPlainText(string);

}

void View::randomGenerateEgg()
{
    if(currentLevel < 5 && currentLevel > 2)
    for(int i =0;i<chickens.size()/8;i++){
            gen6 = QRandomGenerator::system();
            rvalue=gen6->bounded(chickens.size()-1);
            //Even indexs are chickens - convert random value to Odd to generate egg for hens
            if(rvalue % 2 == 0) rvalue++;
            (chickens[rvalue]->generateEgg());
     }
    else if(currentLevel > 4)
        for(int i =0;i<chickens.size()/4;i++){
                gen6 = QRandomGenerator::system();
                rvalue=gen6->bounded(chickens.size());
                (chickens[rvalue]->generateEgg());
         }
}

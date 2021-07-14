#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include <QCursor>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QRandomGenerator64>
#include "Egg.h"
#include "Meat.h"
#include "Superhen.h"
#include "Gift.h"
#include "Bullet.h"
#include "Score.h"
#include "Hen.h"
#include "Spaceship.h"
#include "Pausemenu.h"

class View : public QGraphicsView
{

    Q_OBJECT

private:

    friend class Bullet;
    friend class SpaceShip;
    friend class Egg;
    friend class Chicken;
    friend class Meat;
    friend class Score;
    friend class Hen;
    friend class Menu;
    friend class Lives;
    friend class PauseMenu;

    QTimer * vtimer;  //timer for scheudle
    QGraphicsScene * scene;
    QGraphicsRectItem * rectItem;
    QGraphicsPixmapItem * scoreBoard;
    QGraphicsPixmapItem * heartIcon;
    QGraphicsPixmapItem * heartBack;
    QGraphicsPixmapItem * meatIcon;
    QGraphicsTextItem * levelstext;
    QVector <Chicken *> chickens;
    QMediaPlayer* musicPlayer;
    QRandomGenerator *gen6;
    QRandomGenerator *gen5;
    SpaceShip * spaceship;
    Bullet * bullet;
    Bullet * bullet2;
    Score * score;
    Score * nom;   //numberOfMeats
    Egg * egg;
    Meat* meat;
    Gift* gift;

    bool lose;
    bool pause;
    bool isGifted;


    int sec;
    int giftSecSaver;
    int changeLevelSec;
    int rvalue;
    int row;
    int col;
    int pos_x;
    int endLevelSecond;
    int currentLevel;
    int inputLives;
    int inputScores;
    int inputMeats;

       public:
       QList<QGraphicsItem *> deltedObjects;
       explicit View( int currentLevel , int inputLives , int inputScores , int inputMeats);
       ~View();
       void addChicken(int index);
       void mouseMoveEvent(QMouseEvent * event);
       void addBullet();
       void addSpaceShip();
       void keyPressEvent(QKeyEvent *);
       //function levels
       void level_1();
       void level_2();
       void level_3();
       void level_4();
       void level_5();
       void level_6();
       void setLevelsText(QString string);
       void randomGenerateEgg();




public slots:
void schedule();//funtion to update game every 1s(1000ms)

};

#endif // VIEW_H

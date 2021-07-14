#include "Pausemenu.h"
#include "View.h"
#include "Menu.h"
extern Menu* m;
extern View* v;
PauseMenu::PauseMenu()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080);
    setScene(scene);

    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setFixedSize(1920,1080);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //set background
    setBackgroundBrush(QBrush(QImage(":/ images/background.jpg")));

    //save button
    save=new QPushButton();
    save->setGeometry(690,630,560,80);
    scene->addWidget(save);
    save->setAttribute(Qt::WA_TranslucentBackground);
//   save->setFixedSize(QSize(560,80));
   save->setStyleSheet(
            "border-image: url(:/ images/save_button.png) 3 3 3 3;"
               "padding: 5px;"
);


   Resume=new QPushButton();
   Resume->setGeometry(690,540,560,80);
   scene->addWidget(Resume);

////    connect(loadButton , SIGNAL(clicked()) , this , SLOT(load()));

    Resume->setAttribute(Qt::WA_TranslucentBackground);
//   Resume->setFixedSize(QSize(560,80));
   Resume->setStyleSheet(
            "border-image: url(:/ images/resume-button.png) 3 3 3 3;"
               "padding: 5px;"
);

   menu=new QPushButton();
   menu->setGeometry(10,950,560,80);
   scene->addWidget(menu);

////    connect(loadButton , SIGNAL(clicked()) , this , SLOT(load()));

    menu->setAttribute(Qt::WA_TranslucentBackground);
//   menu->setFixedSize(QSize(560,80));
   menu->setStyleSheet(
            "border-image: url(:/ images/main-menu-button.png) 3 3 3 3;"
               "padding: 5px;"
);
connect(menu , SIGNAL(clicked()) , this , SLOT(goToMenu()));
}

void PauseMenu::keyPressEvent(QKeyEvent * click)
{
     if(click->key()==Qt::Key_1){
            this->hide();
            v->pause=false;
     }
}

void PauseMenu::goToMenu()
{
m->show();
delete this;
}

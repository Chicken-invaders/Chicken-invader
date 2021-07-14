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

    connect(save , SIGNAL(clicked()) , this , SLOT(saveF()));

    save->setAttribute(Qt::WA_TranslucentBackground);
    save->setStyleSheet(
            "border-image: url(:/ images/save_button.png) 3 3 3 3;"
               "padding: 5px;"
);


   Resume=new QPushButton();
   Resume->setGeometry(690,540,560,80);
   scene->addWidget(Resume);

    connect(Resume , SIGNAL(clicked()) , this , SLOT(resumeF()));

   Resume->setAttribute(Qt::WA_TranslucentBackground);
   Resume->setStyleSheet(
            "border-image: url(:/ images/resume-button.png) 3 3 3 3;"
               "padding: 5px;"
);

   menu=new QPushButton();
   menu->setGeometry(10,950,560,80);
   scene->addWidget(menu);

//    connect(loadButton , SIGNAL(clicked()) , this , SLOT(load()));

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
m->timer->stop();
delete this;
delete v;
}

void PauseMenu::resumeF()
{ this->hide();
    v->pause=false;

}

void PauseMenu::saveF()
{
    QFile file(":/Files/Game.txt");
    if ( file.open(QIODevice::WriteOnly) )
    {
        QTextStream stream(&file);
        stream << v->currentLevel << " " << v->spaceship->lives->lives << " " << v->score->scores << " " << v->nom->scores << endl;
    }
    m->show();
    m->timer->stop();
    delete v;
    delete this;

}

#include "Menu.h"
View * v;
Menu::Menu(): QGraphicsView()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080);
    setScene(scene);

    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setFixedSize(1920,1080);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set background
    setBackgroundBrush(QBrush(QImage(":/ images/main_menu.png")));

    newGameButton=new QPushButton();
    newGameButton->setGeometry(690,540,560,80);
    scene->addWidget(newGameButton);

    connect(newGameButton , SIGNAL(clicked()) , this , SLOT(playNewGame()));

     newGameButton->setAttribute(Qt::WA_TranslucentBackground);
    newGameButton->setFixedSize(QSize(560,80));
    newGameButton->setStyleSheet(
             "border-image: url(:/ images/newgame-icon2.png) 3 3 3 3;"
                "padding: 5px;"
);
    quitButton=new QPushButton();
    quitButton->setGeometry(10,950,560,80);
    scene->addWidget(quitButton);

    connect(quitButton , SIGNAL(clicked()) , this , SLOT(exitGame()));

     quitButton->setAttribute(Qt::WA_TranslucentBackground);
    quitButton->setFixedSize(QSize(560,80));
    quitButton->setStyleSheet(
             "border-image: url(:/ images/exit-button.png) 3 3 3 3;"
                "padding: 5px;"
);
    cridtButton=new QPushButton();
    cridtButton->setGeometry(690,720,560,80);
    scene->addWidget(cridtButton);

    connect(cridtButton , SIGNAL(clicked()) , this , SLOT(exitGame()));

     cridtButton->setAttribute(Qt::WA_TranslucentBackground);
    cridtButton->setFixedSize(QSize(560,80));
    cridtButton->setStyleSheet(
             "border-image: url(:/ images/credits_button.png) 3 3 3 3;"
                "padding: 5px;"
);
    loadButton=new QPushButton();
    loadButton->setGeometry(690,630,560,80);
    scene->addWidget(loadButton);

    connect(loadButton , SIGNAL(clicked()) , this , SLOT(load()));

     loadButton->setAttribute(Qt::WA_TranslucentBackground);
    loadButton->setFixedSize(QSize(560,80));
    loadButton->setStyleSheet(
             "border-image: url(:/ images/load_button.png) 3 3 3 3;"
                "padding: 5px;"
);

}

void Menu::playNewGame()
{
    v = new View();
    v->show();
}

void Menu::exitGame()
{
    exit(0);
}

void Menu::load()
{

}

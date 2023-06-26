#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "player.h"


class Game : public QObject{
    QGraphicsScene *scene;
    Player *spaceship;
    QGraphicsView *view;
    QTimer *player_timer;
    QTimer *planet_timer;
    QGraphicsTextItem *txt;
public:
    int score = 0;
    int planet_spawn_speed = 1500;
    int difficulty = 2;
    Game(QWidget *w3, int spaceship_type) : QObject(w3){
        spaceship = new Player(spaceship_type);
        player_timer = new QTimer();
        planet_timer = new QTimer();
        txt = new QGraphicsTextItem(QString("Score: %1").arg(0));
        scene = new QGraphicsScene();
        scene->setSceneRect(0, 0, 1024, 768);
        spaceship->setPos(10, 260);
        //spaceship->setBrush(QBrush(QColor::fromRgb(0, 0, 255)));
        scene->addItem(spaceship);
        //spaceship->setRect(20, 20, 40, 40);
        txt->setDefaultTextColor(Qt::white);
        scene->addItem(txt);
        QImage *background = new QImage("bg.png");
        scene->setBackgroundBrush(QBrush(background->scaled(1024,768))); //nastavi barvu pozadi a scaluje obrazek, ktery je puvodne 800x600
        view = new QGraphicsView(scene, w3);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setFrameStyle(QFrame::NoFrame); ///////////zbaveni se bile cary na okrajich zleva a nahore
        delete background;
        player_timer->start(15);
        planet_timer->start(planet_spawn_speed);
        QObject::connect(player_timer, &QTimer::timeout, [&](){if(Planet::control!=true){spaceship->move();score = spaceship->points;txt->setPlainText(QString("Score: %1").arg(score));}else{player_timer->stop();}}); //snazi se pristoupit k pameti po smazani objektu lodi
        //QObject::connect(player_timer, &QTimer::timeout, [&](){score = spaceship->points;txt->setPlainText(QString("Score: %1").arg(score));});
        QObject::connect(planet_timer, &QTimer::timeout, [&](){if(Planet::control!=true){
            if(score>=50 && score<=150){difficulty = 3;}
            else if(score>150 && score <=250){difficulty = 4;}
            else if(score>250 && score<=350){difficulty = 5;}
            else if(score>350 && score<=500){difficulty = 6;}
            else if(score>500 && score<=700){difficulty = 7;}
            else if(score>700 && score<=900){difficulty = 8;}
            else if(score>900){difficulty = 9;}
            Planet *pla = new Planet(&spaceship->points, difficulty);scene->addItem(pla);}else{planet_timer->stop();}if(planet_spawn_speed>=1000)planet_timer->setInterval(planet_spawn_speed-=5);});
    }
    //////////////////////nefunkcni destruktor///////////////////////////
    ~Game(){
        delete player_timer;
        delete planet_timer;
        delete txt;
        scene->clear();
        delete scene;
        delete view;
    }

};



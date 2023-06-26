#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <QObject>
#include <stdlib.h>
#include <QElapsedTimer>
class Player;


///////////////////////////////////////////////////////PLANET///////////////////////////////////////////////
class Planet : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
public:
    QTimer *t2;
    static bool control;
    int *score_pl;
    int difficulty_pl;
    Planet(int *score, int difficulty) : QObject(), QGraphicsPixmapItem(){
        score_pl = score;
        difficulty_pl = difficulty;
        t2 = new QTimer();
        int random_number = rand() % 690;
        int random_planet_num = rand() % 4;
        setPos(1000, random_number);
        //setRect(0,0,70,70); //nastavi jeji velikost a pozici
        if(random_planet_num==0){
            setPixmap(QPixmap("meteorit_small.png"));
        }else if(random_planet_num==1){
            setPixmap(QPixmap("red_planet.png"));
        }else if(random_planet_num==2){
            setPixmap(QPixmap("green_planet.png"));
        }else{
            setPixmap(QPixmap("blue_planet.png"));
        }
        t2->start(16);
        t2->setTimerType(Qt::PreciseTimer);
        QObject::connect(t2, &QTimer::timeout, this, [&](){if(changePos(difficulty_pl)==true){control = true;};});
    }
    ~Planet(){
        delete t2;
    }
public slots:
    bool changePos(int difficulty);
};




///////////////////////////////////////////////////////MISSILE///////////////////////////////////////////////
class Missile : public QObject , public QGraphicsRectItem{
    Q_OBJECT
public:
    QTimer *t1 = new QTimer();
    int puvodni_x, puvodni_y;
    Player *parent_2;
    Missile(int x, int y, Player *parent){ //konstruktor rakety
        parent_2 = parent;
        puvodni_x = x;
        setRect(x+69,y+36,25,8); //nastavi jeji velikost a pozici
        t1->start(11); //nastavi casovac
        QObject::connect(t1, &QTimer::timeout, this, [&](){fly(parent_2);});
    }
    ~Missile(){
        delete t1;
    }

public slots:
    void fly(Player *parent);
};



///////////////////////////////////////////////////////PLAYER///////////////////////////////////////////////
class Player : public QObject, public QGraphicsPixmapItem{

public:
    int points = 0;
    QElapsedTimer* elapsed;
    Player(int spaceship_type) : QGraphicsPixmapItem(){
        if(spaceship_type == 1){
            setPixmap(QPixmap("spaceship.png"));
        }else if(spaceship_type == 2){
            setPixmap(QPixmap("spaceship2.png"));
        }
        elapsed = new QElapsedTimer();
        elapsed->start();
        this->setFlag(QGraphicsItem::ItemIsFocusable);
        this->setFocus();
    }
    ~Player(){
        delete elapsed;
    };

    bool up = false, down = false, left = false, right = false;
    void keyPressEvent(QKeyEvent *event){
        if(event->key() == Qt::Key_Down){
            down = true;
        }else if(event->key() == Qt::Key_Up){
            up = true;
        }else if(event->key() == Qt::Key_Right){
            right = true;
        }else if(event->key() == Qt::Key_Left){
            left = true;
        }
        
        else if(event->key() == Qt::Key_Space){ //pri stlaceni mezerniku se vytvori novy objekt rakety
            if(elapsed->elapsed() > 160){
                Missile *miss = new Missile(x(), y(), this);
                miss->setBrush(QBrush(QColor::fromRgb(250,0,0))); //nastavi barvu strel
                scene()->addItem(miss); //raketa se prida do sceny
                elapsed->restart();
            }
        }
    }
    void keyReleaseEvent(QKeyEvent *event){
        if(event->key() == Qt::Key_Down){
            down = false;
        }else if(event->key() == Qt::Key_Up){
            up = false;
        }else if(event->key() == Qt::Key_Right){
            right = false;
        }else if(event->key() == Qt::Key_Left){
            left = false;
        }
    }
    void move(){
        if(down == true && y()!=680){
            setPos(x(), y()+5);
        }
        if(up == true && y()!=0){
            setPos(x(), y()-5);
        }
        if(right == true && x()!=400){
            setPos(x()+5, y());
        }
        if(left == true && x()!=0){
            setPos(x()-5, y());
        }
    }
};


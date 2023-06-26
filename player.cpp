#include <QDebug>
#include "player.h"
bool Planet::control = false;

void Missile::fly(Player *parent = 0){
        QList<QGraphicsItem *> colliding = this->collidingItems(); //neni kontrolovano s kym dochazi ke kolizi...pri rychle strelbe se odstranuji kulky navzajem
        if(puvodni_x+10>=950){
            scene()->removeItem(this);
            delete this;
        }else if(!colliding.isEmpty()){
            for(int i=0;i<colliding.size();i++){
                if(typeid(*(colliding.at(i))) == typeid(Planet)){
                    scene()->removeItem(colliding.at(i));
                    delete colliding.at(i);
                    scene()->removeItem(this);
                    delete this;
                    if(parent !=NULL){
                        parent->points += 10;
                    }
                    return;
                }
            }
            setPos(x()+5,y());
            puvodni_x+=5;
        }else{
            setPos(x()+5,y());
            puvodni_x+=5;
        }
    }

bool Planet::changePos(int difficulty){
    QList<QGraphicsItem *> colliding_w_planet = this->collidingItems();
        if(x()<=0){
            *score_pl -=5;
            scene()->removeItem(this);
            delete this;
        }else if(!colliding_w_planet.isEmpty()){
            for(int i=0;i<colliding_w_planet.size();i++){
                if(typeid(*(colliding_w_planet.at(i))) == typeid(Player)){
                    return true;
                }
            }
            setPos(x()-difficulty,y());
        }else{
            setPos(x()-difficulty,y());
        }
        return false;
}
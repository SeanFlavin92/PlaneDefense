#include "PowerUp.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "Game.h"

extern Game * game;

PowerUp::PowerUp(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //random power up type
    randPower = rand() % 2;

    // draw graphics
    if(randPower == 0){
        setPixmap(QPixmap(":/images/powerup.png"));
    } else if(randPower == 1){
        setPixmap(QPixmap(":/images/healthPowerUp.png"));
    }


    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void PowerUp::move()
{
    //move power up down
    setPos(x(),y()+5);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }

    // if power collides with player, destroy power up
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            //increase health for player
            if(game->health->getHealth() < 3 && randPower == 1){
                game->health->increaseHealth();
            }

            // remove power up
            scene()->removeItem(this);
            // delete power up
            delete this;
            return;
        }
    }
}

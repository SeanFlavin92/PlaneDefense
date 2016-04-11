#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <typeinfo>
#include <QApplication>

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // draw graphics
    setPixmap(QPixmap(":/images/enemy.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);
    if (pos().y() > 600){
        //decrease the number of lives and delete enemy
        game->health->decreaseLives();
        //check  if lives is zero
        if(game->health->getLives() == 0){
            qApp->exit();
        }
        scene()->removeItem(this);
        delete this;
    }

    // if player collides with enemy, destroy enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            //increase the score
            game->health->decreaseHealth();
            //check  if health is zero
            if(game->health->getHealth() == 0){
                qApp->exit();
            }
            // remove enemy
            scene()->removeItem(this);
            // delete enemy
            delete this;
            return;
        }
    }
}

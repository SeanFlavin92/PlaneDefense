#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/playerBullet.wav"));

    //set graphics
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800){
            setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+42,y());
        scene()->addItem(bullet);

        //play bullet sound
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        } else if(bulletSound->state() == QMediaPlayer::StoppedState) {
            bulletSound->play();
        }
    }
}

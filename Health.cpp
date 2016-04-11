#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;
    lives = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health) + "\n Lives: " + QString::number(lives)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decreaseHealth(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health) + "\n Lives: " + QString::number(lives)); // Health: 2
}

void Health::increaseHealth()
{
    health++;
    setPlainText(QString("Health: ") + QString::number(health) + "\n Lives: " + QString::number(lives)); // Health: 2
}

int Health::getHealth(){
    return health;
}

void Health::decreaseLives()
{
    lives--;
    setPlainText(QString("Health: ") + QString::number(health) + "\n Lives: " + QString::number(lives)); // Health: 2
}

int Health::getLives()
{
    return lives;
}


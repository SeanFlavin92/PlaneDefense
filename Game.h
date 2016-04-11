#ifndef GAME_H
#define GAME_H

#include "Health.h"
#include "Score.h"
#include "Player.h"
#include "PowerUp.h"
#include "Spawn.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    PowerUp * powerUp;
    Spawn * spawn;
};

#endif // GAME_H

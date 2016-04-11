#include "Spawn.h"
#include "Enemy.h"
#include "PowerUp.h"
#include <QGraphicsScene>
#include <QDebug>

Spawn::Spawn()
{

}

void Spawn::spawnEnemy()
{
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Spawn::spawnPowerUp()
{
    //create a power up
    PowerUp * powerUp = new PowerUp();
    scene()->addItem(powerUp);
}

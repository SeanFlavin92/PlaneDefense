#ifndef SPAWN_H
#define SPAWN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Spawn: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spawn();

public slots:
    void spawnEnemy();
    void spawnPowerUp();
};

#endif // SPAWN_H

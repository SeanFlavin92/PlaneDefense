#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsPixmapItem>
#include <QObject>

class PowerUp: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PowerUp();

public slots:
    void move();

private:
    int randPower;
};

#endif // POWERUP_H

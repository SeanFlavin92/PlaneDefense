#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

//Bullet needs to extend QObject so it can use slots and signals
class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // BULLET_H

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decreaseHealth();
    void increaseHealth();
    int getHealth();

    void decreaseLives();
    int getLives();
private:
    int health;
    int lives;
};

#endif // HEALTH_H

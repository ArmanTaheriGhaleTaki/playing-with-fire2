#ifndef PLYING_WITH_FIRE2_BOMB_H
#define PLYING_WITH_FIRE2_BOMB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "Player.h"
#include "../views/Brick.h"

class Bomb : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

private:
    int width{};
    int height{};
    int pos_x{};
    int pos_y{};
    QTimer *BombTimer;
    QList<Brick *> *bricks;

public:


    Bomb(int posX, int posY, int width, int height, QList<Brick *> *bricks);

public slots:

    void Exploding();


};


#endif //PLYING_WITH_FIRE2_BOMB_H

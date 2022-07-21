#include "Bomb.h"
#include "../views/Brick.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include "../Home/Game.h"
#include <cmath>


Bomb::Bomb(int posX,int posY,int width,int height, QList<Brick*> *bricks): pos_x{posX},pos_y{posY},width{width},height{height},bricks{bricks},QObject()
{

    QPixmap pixmap(":/images/bomb");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
    auto BombTimer = new QTimer();
    connect(BombTimer, &QTimer::timeout, this , &Bomb::Exploding);
    BombTimer->start(1500);

}
void Bomb::Exploding()
{

    // destroying bricks
    for (const auto brick : *bricks)
    {
        auto brick_x = brick->x();
        auto brick_y = brick->y();
        auto distance = sqrt(pow(brick_x - pos_x,2)+pow(brick_y - pos_y,2));
        auto distanceBetweenPlayer_Bomb = sqrt(pow(brick_x - pos_x,2)+pow(brick_y - pos_y,2));
        if(distance < 120)
        {
            scene()->removeItem(brick);
//            delete brick;
//            return;
        }
    }

    scene()->removeItem(this);
    delete this;

}




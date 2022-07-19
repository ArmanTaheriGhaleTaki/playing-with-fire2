#include "Bomb.h"
#include "../views/Brick.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include "../Home/Game.h"

Bomb::Bomb(int posX,int posY,int width,int height): width{width},height{height},timeIntervals{0},QObject()
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
        scene()->removeItem(this);
        delete this;
}


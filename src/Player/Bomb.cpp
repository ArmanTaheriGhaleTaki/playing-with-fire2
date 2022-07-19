#include "Bomb.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Bomb::Bomb(int width,int height): width{width},height{height},timeIntervals{0},QObject()
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


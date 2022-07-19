#include "Bomb.h"
#include "../views/Brick.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include "../Home/Game.h"

Bomb::Bomb(int posX,int posY,int width,int height): pos_x{posX},pos_y{posY},width{width},height{height},QObject()
{

    QPixmap pixmap(":/images/bomb");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
    auto BombTimer = new QTimer();
    connect(BombTimer, &QTimer::timeout, this , &Bomb::Exploding);
    BombTimer->start(1500);
}
void Bomb::Exploding() {
    // if Bomb collides with bricks
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Brick)) {
            scene()->removeItem(colliding_items[i]);
        }
            // if Bomb collides with players
        else if (typeid(*(colliding_items[i])) == typeid(Player)) {
            scene()->removeItem(colliding_items[i]);
//                delete colliding_items[i];
//                delete this;
//                return;
        }
    }
    scene()->removeItem(this);
    delete this;
}

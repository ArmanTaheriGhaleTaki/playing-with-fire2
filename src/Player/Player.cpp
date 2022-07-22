#include "Player.h"
#include "../Home/Game.h"

#include <QGraphicsTextItem>

Player::Player(const char* icon,int width,int height,int NumberOfBombs): width(width),height(height),NumberOfBombs{NumberOfBombs} {

    QPixmap pixmap(icon);
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);

}

QRectF Player::boundingRect() const {

    auto player = QGraphicsPixmapItem::boundingRect();
    player.setWidth(width);
    player.setHeight(height);
    return QGraphicsPixmapItem::boundingRect();
}
void Player::DecreaseHealth()
{
    HitPoint--;
}

void Player::increaseScore(int amountOfIncreasing)
{
    score+=amountOfIncreasing;
}

void Player::setHitPoint(int hp)
{
    HitPoint = hp;
}

int Player::getHitPoint()
{
    return HitPoint;
}
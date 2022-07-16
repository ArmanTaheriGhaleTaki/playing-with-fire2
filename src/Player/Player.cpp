#include "Player.h"

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

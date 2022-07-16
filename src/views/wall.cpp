#include "wall.h"

Wall::Wall(int width , int height):width{width},height{height},Block(width , height)
{
    QPixmap pixmap(":/images/wall");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

QRectF Wall::boundingRect() const {

    auto wall = QGraphicsPixmapItem::boundingRect();
    wall.setWidth(width);
    wall.setHeight(height);
    return QGraphicsPixmapItem::boundingRect();
}

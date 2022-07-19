#include "Brick.h"

Brick::Brick(int width, int height) :width{width},height{height},Block(width, height)
{
    QPixmap pixmap(":/images/brick");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

QRectF Brick::boundingRect() const {
    auto brick = QGraphicsPixmapItem::boundingRect();
    brick.setWidth(width);
    brick.setHeight(height);
    return QGraphicsPixmapItem::boundingRect();
}

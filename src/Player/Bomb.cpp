#include "Bomb.h"
#include <QGraphicsTextItem>

Bomb::Bomb(int width,int height): width{width},height{height}
{

    QPixmap pixmap(":/images/bomb");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);

}


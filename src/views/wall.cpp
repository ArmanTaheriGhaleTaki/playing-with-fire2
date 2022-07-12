#include "wall.h"

Wall::Wall(int width , int height):Block(width , height)
{
    QPixmap pixmap(":/images/stone");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

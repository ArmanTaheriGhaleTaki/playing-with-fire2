#include "Brick.h"

Brick::Brick(int width, int height) : Block(width, height)
{
    QPixmap pixmap(":/images/brick");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

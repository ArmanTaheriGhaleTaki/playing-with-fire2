#include "box.h"

Box::Box(int width , int height):Block(width , height)
{
    QPixmap pixmap(":/images/brick");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
}

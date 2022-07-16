#ifndef WALL_H
#define WALL_H

#include"block.h"

class Wall:public Block
{
private:
    int width{};
    int height{};
public:
    Wall(int width , int height);

    QRectF boundingRect() const override;
};

#endif // WALL_H

#ifndef WALL_H
#define WALL_H

#include"block.h"

class Wall:public Block
{
public:
    Wall(int width , int height);
};

#endif // WALL_H

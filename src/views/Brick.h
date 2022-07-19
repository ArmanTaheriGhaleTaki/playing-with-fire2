#ifndef PLYING_WITH_FIRE2_BRICK_H
#define PLYING_WITH_FIRE2_BRICK_H


#include "block.h"

class Brick: public Block
{
private:
    int width{};
    int height{};
public:
    Brick(int width,int height);

    QRectF boundingRect() const override;
};


#endif //PLYING_WITH_FIRE2_BRICK_H

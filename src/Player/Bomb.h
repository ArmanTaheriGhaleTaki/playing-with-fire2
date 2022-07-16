#ifndef PLYING_WITH_FIRE2_BOMB_H
#define PLYING_WITH_FIRE2_BOMB_H

#include <QGraphicsPixmapItem>

class Bomb:public QGraphicsPixmapItem {
private:
    int width{};
    int height{};
public:

    int CountOfBombs{0};
    Bomb(int width,int height);



};


#endif //PLYING_WITH_FIRE2_BOMB_H

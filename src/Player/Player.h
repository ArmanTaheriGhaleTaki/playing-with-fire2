#ifndef PLYING_WITH_FIRE2_PLAYER_H
#define PLYING_WITH_FIRE2_PLAYER_H

#include <QGraphicsPixmapItem>
class Player : public QGraphicsPixmapItem {
private:
    int number_of_bombs{200};
public:
    Player(int setPositionX,int setPositionY,const char* icon );

};


#endif //PLYING_WITH_FIRE2_PLAYER_H

#include "Player.h"

Player::Player(int setPositionX,int setPositionY,const char* icon) {

    QPixmap pixmap(icon);
    setPixmap(pixmap);

    setPos(setPositionX,setPositionY);


}

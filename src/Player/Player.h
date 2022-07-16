#ifndef PLYING_WITH_FIRE2_PLAYER_H
#define PLYING_WITH_FIRE2_PLAYER_H

#include <QGraphicsPixmapItem>
class Player : public QGraphicsPixmapItem {
private:
    int number_of_bombs{200};
    int width{};
    int height{};
public:
    Player(const char* icon,int width,int height);

    QRectF boundingRect() const override;



};


#endif //PLYING_WITH_FIRE2_PLAYER_H

#ifndef PLYING_WITH_FIRE2_PLAYER_H
#define PLYING_WITH_FIRE2_PLAYER_H

#include <QGraphicsPixmapItem>
class Player : public QGraphicsPixmapItem {
private:

    int width{};
    int height{};
public:

    int NumberOfBombs{};
    Player(const char* icon,int width,int height,int NumberOfBombs);

    QRectF boundingRect() const override;



};


#endif //PLYING_WITH_FIRE2_PLAYER_H

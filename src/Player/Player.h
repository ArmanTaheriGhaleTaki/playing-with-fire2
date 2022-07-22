#ifndef PLYING_WITH_FIRE2_PLAYER_H
#define PLYING_WITH_FIRE2_PLAYER_H

#include <QGraphicsPixmapItem>

class Player : public QGraphicsPixmapItem {
private:

    int width{};
    int height{};
    int HitPoint{5};

public:

    int NumberOfBombs{};
    int score{0};

    void DecreaseHealth();
    void increaseScore(int amountOfIncreasing);
    Player(const char* icon,int width,int height,int NumberOfBombs);
    QRectF boundingRect() const override;

    void setHitPoint(int hp);
    int getHitPoint();


};


#endif //PLYING_WITH_FIRE2_PLAYER_H

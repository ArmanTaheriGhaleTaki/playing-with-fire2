#ifndef PLYING_WITH_FIRE2_BOMB_H
#define PLYING_WITH_FIRE2_BOMB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Bomb:public QObject, public QGraphicsPixmapItem  {
    Q_OBJECT

private:
    int width{};
    int height{};
    int timeIntervals;
    QTimer *BombTimer;

public:


    Bomb(int width,int height);

public slots:
    void Exploding();



};


#endif //PLYING_WITH_FIRE2_BOMB_H

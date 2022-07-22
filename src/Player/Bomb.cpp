#include "Bomb.h"
#include "../views/Brick.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include "../Home/Game.h"
#include <cmath>


Bomb::Bomb(int posX, int posY, int width, int height, QList<Brick *> *bricks, QList<Player *> *players,
           QString PlayerRecognizer) : pos_x{posX}, pos_y{posY}, width{width}, height{height}, bricks{bricks},
                                       players{players}, PlayerRecognizer{PlayerRecognizer}, QObject()
{

    QPixmap pixmap(":/images/bomb");
    pixmap = pixmap.scaled(width,height);
    setPixmap(pixmap);
    auto BombTimer = new QTimer();
    connect(BombTimer, &QTimer::timeout, this , &Bomb::Exploding);
    BombTimer->start(5000);

}
void Bomb::Exploding()
{

    // destroying bricks

    Game *game;
    for (const auto brick : *bricks)
    {
        auto brick_x = brick->x();
        auto brick_y = brick->y();
        auto distance = sqrt(pow(brick_x - pos_x,2)+pow(brick_y - pos_y,2));
        auto distanceBetweenPlayer_Bomb = sqrt(pow(brick_x - pos_x,2)+pow(brick_y - pos_y,2));
        if((distance <= 120)&&((( pos_x/60==brick_x/60)&&!(((pos_x/60)%2==0)&&(pos_y/60)%2==1))||((pos_y/60==brick_y/60)&&!(((pos_x/60)%2==1)&&(pos_y/60)%2==0))))
        {
            scene()->removeItem(brick);
            bricks->removeAt(bricks->indexOf(brick));
            if (PlayerRecognizer == "player_1")
                players->at(0)->increaseScore(25);
            else if (PlayerRecognizer == "player_2")
                players->at(1)->increaseScore(25);
          }
    }

    auto player1 = players->at(0);
    auto player2 = players->at(1);
    auto distancePlayer1_Bomb = sqrt(pow(player1->x() - pos_x, 2) + pow(player1->y() - pos_y, 2));
    auto distancePlayer2_Bomb = sqrt(pow(player2->x() - pos_x, 2) + pow(player2->y() - pos_y, 2));

    if(distancePlayer1_Bomb < 120)
    {
        players->at(0)->DecreaseHealth();
        if (players->at(0)->getHitPoint() == 0)
        {
            players->at(1)->increaseScore(50);
            game->close();
        }
    }
    else if(distancePlayer2_Bomb < 120)
    {
        players->at(1)->DecreaseHealth();
        if (players->at(1)->getHitPoint() == 0)
        {
            players->at(0)->increaseScore(50);
            game->close();
        }
    }


    scene()->removeItem(this);
    delete this;

}




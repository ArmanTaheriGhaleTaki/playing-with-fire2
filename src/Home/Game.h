#ifndef RESOURCES_QRC_GAME_H
#define RESOURCES_QRC_GAME_H

#include <QGraphicsView>
#include "../Player/Player.h"
#include "../views/wall.h"
#include "../Player/Bomb.h"
#include "../views/Brick.h"


class Game : public QGraphicsView{

public:
    Game(QString name_player1,QString name_player2,QString hp);

    QList<Player*> players{};
    QList<Wall*> walls{};
    QList<Brick*> bricks{};
    void getPos ();


protected:
    void keyPressEvent(QKeyEvent *event) override;

};


#endif //RESOURCES_QRC_GAME_H

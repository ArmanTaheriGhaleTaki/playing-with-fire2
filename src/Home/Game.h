#ifndef RESOURCES_QRC_GAME_H
#define RESOURCES_QRC_GAME_H

#include <QGraphicsView>

class Game : public QGraphicsView{

public:
    Game(QString name_player1,QString name_player2,QString hp);

};


#endif //RESOURCES_QRC_GAME_H

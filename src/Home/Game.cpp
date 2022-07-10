#include "Game.h"

Game::Game(QString name_player1,QString name_player2,QString hp) : QGraphicsView(){

    setFixedSize(750,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,750,750);
    scene->setBackgroundBrush(QBrush(QImage(":/images/ground")));
    setScene(scene);


}

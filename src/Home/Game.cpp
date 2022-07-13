#include "Game.h"
#include "../views/wall.h"
#include "../views/box.h"

Game::Game(QString name_player1,QString name_player2,QString hp) : QGraphicsView(){

    // set fixed size
    setFixedSize(750,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    // create ground
    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,750,750);
    scene->setBackgroundBrush(QBrush(QImage(":/images/ground")));
    setScene(scene);

    auto blockWidth = width()/15;
    auto blockHeight =height()/15;

    // put blocks on ground
    for(int i =0 ; i<15;i++)
        for(int j =0;j<15;j++){
            if(i!=0&&i!=14&&j!=0&&j!=14&&(j%2!=0||i%2!=0))
                continue;
            auto wall = new Wall(blockWidth, blockHeight);
                    scene->addItem(wall);
                    wall->setPos(blockWidth*i,blockHeight*j);
        }


    // add players to scene
    auto player1 = new Player(6,6,":/images/player1");
    scene->addItem(player1);
    setScene(scene);

    auto player2 = new Player(600,600,":/images/player2");
    scene->addItem(player2);
    setScene(scene);
}

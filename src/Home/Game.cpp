#include "Game.h"
#include "../views/wall.h"
#include "../views/box.h"
#include <QKeyEvent>

Game::Game(QString name_player1,QString name_player2,QString hp) : QGraphicsView(){

    // set fixed size
    setFixedSize(900,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    // create ground
    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,900,900);
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
                    walls.append(wall);
        }


    // add players to scene
    auto player1 = new Player(":/images/player1",33,45);
    scene->addItem(player1);
    setScene(scene);
    player1->setPos(75,70);
    players.append(player1);

    auto player2 = new Player(":/images/player2",33,45);
    scene->addItem(player2);
    setScene(scene);
    player2->setPos(795,770);
    players.append(player2);
}


// control players
void Game::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);


    // control player 1
    auto player_1 = players.at(0);

    auto player_1Width = player_1->boundingRect().width();
    auto player_1Height = player_1->boundingRect().height();

    auto newX_p1 = player_1->x();
    auto newY_p1 = player_1->y();

    if(event->key() == Qt::Key_S)
        newY_p1 = player_1->y() + 7;

    if(event->key() == Qt::Key_W)
        newY_p1 = player_1->y() - 7;

    if(event->key() == Qt::Key_A)
        newX_p1 = player_1->x() - 7;

    if(event->key() == Qt::Key_D)
        newX_p1 = player_1->x() + 7;

    // collision with walls
    for(const auto wall:walls)
    {

        if(wall->x() < newX_p1 && wall->x() + wall->boundingRect().width() > newX_p1
           && wall->y() < newY_p1 && wall->y() + wall->boundingRect().height() > newY_p1)
            return;
        if(wall->x() < newX_p1 + player_1Width && wall->x() + wall->boundingRect().width() > newX_p1 + player_1Width
           && wall->y() < newY_p1 && wall->y() + wall->boundingRect().height() > newY_p1)
            return;
        if(wall->x() < newX_p1 + player_1Width && wall->x() + wall->boundingRect().width() > newX_p1 + player_1Height
           && wall->y() < newY_p1 + player_1Height && wall->y() + wall->boundingRect().height() > newY_p1 + player_1Height)
            return;
        if(wall->x()<newX_p1 && wall->x() + wall->boundingRect().width() > newX_p1
           && wall->y() < + player_1Height && wall->y() + wall->boundingRect().height() > newY_p1 + player_1Width)
            return;
    }

    player_1->setPos(newX_p1,newY_p1);




    // control player 2
    auto player_2 = players.at(1);

    auto player_2Width = player_2->boundingRect().width();
    auto player_2Height = player_2->boundingRect().height();

    auto newX_p2 = player_2->x();
    auto newY_p2 = player_2->y();

    if(event->key() == Qt::Key_8)
        newY_p2 = player_2->y() - 7;

    if(event->key() == Qt::Key_2)
        newY_p2 = player_2->y() + 7;

    if(event->key() == Qt::Key_4)
        newX_p2 = player_2->x() - 7;

    if(event->key() == Qt::Key_6)
        newX_p2 = player_2->x() + 7;

    // collision with walls
    for(const auto wall:walls)
    {

        if(wall->x() < newX_p2 && wall->x() + wall->boundingRect().width() > newX_p2
           && wall->y() < newY_p2 && wall->y() + wall->boundingRect().height() > newY_p2)
            return;
        if(wall->x() < newX_p2 + player_2Width && wall->x() + wall->boundingRect().width() > newX_p2 + player_2Width
           && wall->y() < newY_p2 && wall->y() + wall->boundingRect().height() > newY_p2)
            return;
        if(wall->x() < newX_p2 + player_2Width && wall->x() + wall->boundingRect().width() > newX_p2 + player_2Height
           && wall->y() < newY_p2 + player_2Height && wall->y() + wall->boundingRect().height() > newY_p2 + player_2Height)
            return;
        if(wall->x()<newX_p2 && wall->x() + wall->boundingRect().width() > newX_p2
           && wall->y() < + player_2Height && wall->y() + wall->boundingRect().height() > newY_p2 + player_2Width)
            return;
    }

    player_2->setPos(newX_p2,newY_p2);

}



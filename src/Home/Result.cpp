#include "Result.h"
#include "../views/Label.h"


Result::Result(QString winner,int scoreOfPlayer1,int scoreOfPlayer2)
{


    // set fixed size

    setFixedSize(443,390);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    // create scene

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,443,390);
    scene->setBackgroundBrush(QBrush(QImage(":/images/result")));
    setScene(scene);

    // the winner of game
    auto winnerLabel = new Label(50,"white"); // first part is size of font and second part is color
    winnerLabel->setPlainText(winner);
    scene->addItem(winnerLabel);
    winnerLabel->setPos(130,230);

    // score of players
    auto scoreOfPlayer1Label = new Label(25,"white");
    scoreOfPlayer1Label->setPlainText(QString::number(scoreOfPlayer1));
    scene->addItem(scoreOfPlayer1Label);
    scoreOfPlayer1Label->setPos(40,300);

    auto scoreOfPlayer2Label = new Label(25,"white");
    scoreOfPlayer2Label->setPlainText(QString::number(scoreOfPlayer2));
    scene->addItem(scoreOfPlayer2Label);
    scoreOfPlayer2Label->setPos(370,300);


}

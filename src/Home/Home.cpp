#include "Home.h"
#include "../views/Label.h"
#include "../views/Button.h"
#include "Game.h"

Home::Home() {

    setFixedSize(800,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,800);
    scene->setBackgroundBrush(QBrush(QImage(":/images/menu")));
    setScene(scene);


    textField_player1 = new TextField(150,39);
    textField_player1->setPlainText(" ");
    scene->addItem(textField_player1);
    textField_player1->setPos(240,430);

    textField_player2 = new TextField(150,39);
    textField_player2->setPlainText(" ");
    scene->addItem(textField_player2);
    textField_player2->setPos(440,430);

    textField_hp = new TextField(46,39);
    textField_hp->setPlainText(" ");
    scene->addItem(textField_hp);
    textField_hp->setPos(398,545);

    auto name_label = new Label();
    name_label->setPlainText("vs ");
    scene->addItem(name_label);
    name_label->setPos(392,415);

    auto hp_label = new Label();
    hp_label->setPlainText("HP:");
    scene->addItem(hp_label);
    hp_label->setPos(322,530);

    auto start_button = new Button(100,50);
    start_button->setPlainText(" Start ->");
    scene->addItem(start_button);
    start_button->setPos(640,680);


    connect (start_button, &Button::onPress,this, &Home::onGameStart);

}

void Home::onGameStart() {

    auto name_player1 = textField_player1->toPlainText();
    auto name_player2 = textField_player2->toPlainText();
    auto hp = textField_hp->toPlainText();
    close();
    (new Game(name_player1,name_player2,hp))->show();


}
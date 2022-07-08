#include "Home.h"
#include "../views/TextField.h"

Home::Home() {

//    setFixedSize(800,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QBrush(QImage("C:/Users/yzdan/menu.jpg")));
    setScene(scene);


    auto textField = new TextField(200,50);
    textField->setPlainText("salam");
    scene->addItem(textField);
    textField->setPos(width()/2,height()/2);

}
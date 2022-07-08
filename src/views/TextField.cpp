#include "TextField.h"
#include <QFont>
#include <QPainter>

TextField::TextField(int width, int height): width(width),height(height), QGraphicsTextItem(){

    QFont font;
    font.setPixelSize(50);
    font.setBold(true);
    setFont(font);


    setTextInteractionFlags(Qt::TextEditorInteraction);




}

void TextField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap("C:/Users/yzdan/menu.jpg");
    pixmap = pixmap.scaled(width,height);

    painter->setBrush(pixmap);
    painter->drawRect(boundingRect());
    QGraphicsTextItem::paint(painter, option, widget);
}

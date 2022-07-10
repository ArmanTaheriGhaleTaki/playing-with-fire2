#include "Button.h"
#include <QFont>
#include <QPainter>
#include <QTextDocument>


Button::Button(int width, int height): width(width),height(height),QGraphicsTextItem() {



    QFont font;
    font.setPixelSize(22);
    font.setBold(true);
    setFont(font);

    setTextWidth(width);

    document()->setDocumentMargin(4);


}


void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QPixmap pixmap(":/images/button");
    pixmap = pixmap.scaled(width,height);

    painter->setBrush(pixmap);
    painter->drawRect(boundingRect());

    QGraphicsTextItem::paint(painter,option, widget);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsTextItem::mousePressEvent(event);

    emit onPress();
}



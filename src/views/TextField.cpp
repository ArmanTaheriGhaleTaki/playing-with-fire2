#include "TextField.h"
#include <QFont>
#include <QTextDocument>
#include <QStyleOptionGraphicsItem>
#include <QPainter>

TextField::TextField(int width, int height): width(width),height(height), QGraphicsTextItem(){

    QFont font;
    font.setPixelSize(22);
    font.setBold(true);
    setFont(font);


    setTextInteractionFlags(Qt::TextEditorInteraction);


    setTextWidth(width);

    document()->setDocumentMargin(4);

}

void TextField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap(":/images/icon");
    pixmap = pixmap.scaled(width,height);

    painter->setBrush(pixmap);
    painter->drawRect(boundingRect());

    QStyleOptionGraphicsItem newOption(*option);
    newOption.state = QStyle::State_None;

    QGraphicsTextItem::paint(painter, &newOption, widget);
}

QRectF TextField::boundingRect() const {
    auto rect = QGraphicsTextItem::boundingRect();
    rect.setWidth(width);
    rect.setHeight(height);
    return QGraphicsTextItem::boundingRect();
}

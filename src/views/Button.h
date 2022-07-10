#ifndef RESOURCES_QRC_BUTTON_H
#define RESOURCES_QRC_BUTTON_H

#include <QGraphicsTextItem>

class Button: public QGraphicsTextItem {
    Q_OBJECT

private:
    int width{};
    int height{};
public:
    Button(int width,int height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
        void onPress();

};




#endif //RESOURCES_QRC_BUTTON_H

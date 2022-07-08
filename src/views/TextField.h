#ifndef PLYING_WITH_FIRE2_TEXTFIELD_H
#define PLYING_WITH_FIRE2_TEXTFIELD_H


#include <QGraphicsTextItem>

class TextField : public QGraphicsTextItem {

private:
    int width{};
    int height{};
public:
    TextField(int width, int height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};



#endif //PLYING_WITH_FIRE2_TEXTFIELD_H

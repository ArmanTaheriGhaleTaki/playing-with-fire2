#ifndef PLYING_WITH_FIRE2_HOME_H
#define PLYING_WITH_FIRE2_HOME_H

#include <QGraphicsView>
#include "../views/TextField.h"

class Home : public QGraphicsView {

Q_OBJECT
private:
    TextField *textField_player1;
    TextField *textField_player2;
    TextField *textField_hp;
public:
    Home();

public slots:
    void onGameStart();

};


#endif //PLYING_WITH_FIRE2_HOME_H

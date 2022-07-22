#ifndef PLYING_WITH_FIRE2_RESULT_H
#define PLYING_WITH_FIRE2_RESULT_H

#include <QGraphicsView>


class Result : public QGraphicsView
{
public:

    Result(QString winner,int scoreOfPlayer1,int scoreOfPlayer2);
};


#endif //PLYING_WITH_FIRE2_RESULT_H

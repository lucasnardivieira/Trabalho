#ifndef INIMIGO2_H
#define INIMIGO2_H

#include "game.h"
#include <QGraphicsRectItem>
#include <QObject>

class Inimigo2: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Game *game;

public:
    Inimigo2(Game *g);
public slots:
    void move2();
};

#endif // INIMIGO2_H

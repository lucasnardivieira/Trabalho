#ifndef INIMIGO_H
#define INIMIGO_H

#include "game.h"
#include <QGraphicsRectItem>
#include <QObject>

class Inimigo: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Game *game;

public:
    Inimigo(Game *g);
public slots:
    void move();
};

#endif // INIMIGO_H

#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
#include <QObject>
#include <QGraphicsRectItem>
#include "game.h"

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Game *game;

public:
    Player(Game *g);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
    void spawn2();
};

#endif // PLAYER_H

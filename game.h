#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include "pontos.h"
#include "perdas.h"
#include "janela.h"

class Game: public QGraphicsView//, public Janela
{

public:
    Game(QWidget * parent=0);

    QGraphicsScene *scene;
    Pontos *pontos;
    Perdas *perdas;

};

#endif // GAME_H

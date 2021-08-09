#include "inimigo.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

Inimigo::Inimigo(Game *g): QObject(), QGraphicsRectItem()
{
    game = g;

    //posição inicial do inimigo
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //desenhando o inimigo
    setRect(0,0,100,100);

    //conexao com o spawner do inimigo
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(40);
}

void Inimigo::move()
{
    //movimento do inimigo
    setPos(x(),y()+5);
    //deletando o inimigo quando sair da tela
    if(pos().y() >600 )
    {
        //diminuindo a pontuaçao
        game->perdas->perdeu();
        scene()->removeItem(this);
        delete this;
    }
}

#include "inimigo2.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"
#include "player.h"


Inimigo2::Inimigo2(Game *g): QObject(), QGraphicsRectItem()
{
    game = g;
    //posição inicial do inimigo
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //desenhando o inimigo 2
    setRect(0,0,50,50);

    //conexao com o spawner do inimigo
    QTimer *timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(move2()));

    timer2->start(40);
}

void Inimigo2::move2()
{
    //movimento do inimigo
    setPos(x(),y()+4);
    //deletando o inimigo quando sair da tela
    if(pos().y() > 600 )
    {
        scene()->removeItem(this);
        delete this;
    }
    //reduzindo pontuaçao se encostar nesse inimigo
    QList<QGraphicsItem*> itensColisao = collidingItems();
    for(int i = 0, n = itensColisao.size(); i<n;++i)
    {
        if(typeid(*(itensColisao[i]))==typeid(Player))
        {
            //deleta o inimigo e reduz vida
            game->perdas->perdeu();
            scene()->removeItem(this);
            delete this;
        }
    }
}

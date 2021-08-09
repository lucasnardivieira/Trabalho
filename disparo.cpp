#include "disparo.h"
#include "game.h"
#include "inimigo.h"
#include "inimigo2.h"
#include <QTimer>
//#include <QDebug>
//#include <QGraphicsScene>
//#include <QList>
//teste
Disparo::Disparo(Game *g)
{
    game = g;

    //desenhando o tiro
    setRect(0,0,10,15);

    //conexao
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(40);
}

void Disparo::move()
{
    //COLISAO COM INIMIGO
    QList<QGraphicsItem*> itensColisao = collidingItems();
    for(int i = 0, n = itensColisao.size(); i<n;++i)
    {
        if(typeid(*(itensColisao[i]))==typeid(Inimigo))
        {
            //pontuando
            game->pontos->pontuacao();

            //deleta o inimigo e o tiro
            scene()->removeItem(itensColisao[i]);
            scene()->removeItem(this);
            delete itensColisao[i];
            delete this;
            return;
        }
        else if(typeid(*(itensColisao[i]))==typeid(Inimigo2))
        {

            //deleta o tiro
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    //atirando
    setPos(x(),y()-10);
     //deletando o tiro quando sair da tela
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

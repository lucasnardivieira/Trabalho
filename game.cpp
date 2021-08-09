#include "game.h"
#include "inimigo.h"
#include "player.h"
#include "janela.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QFont>

Game::Game(QWidget *parent)
{
    //criando cena
    QGraphicsScene *cena = new QGraphicsScene();
    cena->setSceneRect(0,0,800,600);

    //impedindo que a janela dê scrool quando atira
    setScene(cena);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QWidget::setFixedSize(800,600);

    //criando um personagem
    Player *ator = new Player(this);
    ator->setRect(0,0,50,50);
    //colocando o player no centro da cena
    ator->setPos(400,500);
    //focando no personagem
    ator->setFlag(QGraphicsItem::ItemIsFocusable);
    ator->setFocus();
    //colocando o personagem na cena
    cena->addItem(ator);

    //criando a pontuaçao
    pontos = new Pontos();
    cena->addItem(pontos);

    //criando o limite de perdas
    perdas = new Perdas();
    perdas->setPos(perdas->x(),perdas->y()+50);
    cena->addItem(perdas);

//    //mostrando a cena
//    QGraphicsView *view = new QGraphicsView(cena);

    //spawnando inimigos
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), ator, SLOT(spawn()));
    timer->start(2000);
    //inimigo 2
    QTimer *timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), ator, SLOT(spawn2()));
    timer2->start(10000);

    show();
}

#include "player.h"
#include "game.h"
#include "disparo.h"
#include "inimigo.h"
#include "inimigo2.h"

Player::Player(Game *g)
{
    game = g;
}

//movimentação do personagem
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x()+100 < 800)
        setPos(x()+10, y());
    }

    else if(event->key() == Qt::Key_Space){
        //criando a arma
        Disparo *tiro = new Disparo(game);
        tiro->setPos(x()+20,y());
        scene()->addItem(tiro);
    }
}

void Player::spawn()
{
    Inimigo *enemy= new Inimigo(game);
    scene()->addItem(enemy);
}

void Player::spawn2()
{
    Inimigo2 *enemy2 = new Inimigo2(game);
    scene()->addItem(enemy2);
}

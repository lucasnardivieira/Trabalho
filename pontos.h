#ifndef PONTOS_H
#define PONTOS_H

#include <QGraphicsTextItem>

class Pontos: public QGraphicsTextItem
{
private:
    int pontos;

public:
    Pontos(QGraphicsItem *parent=0);
    void pontuacao();
    int getPontos();
};

#endif // PONTOS_H

#include "pontos.h"
#include <QFont>

Pontos::Pontos(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    pontos = 0;

    //imprimindo na tela
    setPlainText("Pontos: " + QString::number(pontos));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));

}

void Pontos::pontuacao()
{
    pontos++;
    //atualizando a pontuaçao na tela
    setPlainText("Pontos: " + QString::number(pontos));
}

int Pontos::getPontos()
{
    return pontos;
}

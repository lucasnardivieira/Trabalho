#include "perdas.h"
#include <QFont>

Perdas::Perdas(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    perdas = 3;

    //imprimindo na tela
    setPlainText("Perdas: " + QString::number(perdas));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}

void Perdas::perdeu()
{
    perdas--;
    //atualizando a pontuaçao na tela
    setPlainText("Perdas: " + QString::number(perdas));
}

int Perdas::getPerdas()
{
    return perdas;
}

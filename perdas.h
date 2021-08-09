#ifndef PERDAS_H
#define PERDAS_H

#include <QGraphicsTextItem>

class Perdas: public QGraphicsTextItem
{
public:
    Perdas(QGraphicsItem *parent=0);
    void perdeu();
    int getPerdas();

private:
    int perdas;
};

#endif // PERDAS_H

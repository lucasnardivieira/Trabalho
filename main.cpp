#include <QApplication>
#include "janela.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    //Janela j;
    //j.show();
    Game *g = new Game();
    g->show();

    return a.exec();
}


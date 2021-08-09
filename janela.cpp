#include "janela.h"
#include "game.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QShortcut>

Janela::Janela(QWidget *parent) : QMainWindow(parent)
{
    //posicao inicial da janela
    setGeometry(300,100,660,680);

    //adicionando barra de  menu e suas opcoes (acoes)
    QMenuBar *barra = new QMenuBar(this);

    QMenu *menuArquivo = new QMenu("Arquivo", this);
    QMenu *menuNovo = new QMenu("Novo Jogo", this);
    QMenu *menuLimpar = new QMenu("Limpar Jogo", this);
    barra->addMenu(menuArquivo);
    barra->addMenu(menuNovo);
    barra->addMenu(menuLimpar);
    barra->adjustSize();

    QAction *acaoFacil = new QAction("Nível Fácil", this);
    QAction *acaoDificil = new QAction("Nível Difícil", this);
    QAction *acaoAbrir = new QAction("Abrir", this);
    QAction *acaoSalvar = new QAction("Salvar", this);
    QAction *acaoSair = new QAction("Sair", this);

    menuNovo->addAction(acaoFacil);
    menuNovo->addAction(acaoDificil);
    menuArquivo->addAction(acaoAbrir);
    menuArquivo->addAction(acaoSalvar);
    menuArquivo->addAction(acaoSair);

    //adicionando atalhos de teclado para as opcoes
    acaoFacil->setShortcut(Qt::Key_F5);
    acaoDificil->setShortcut(Qt::Key_F6);
    acaoAbrir->setShortcut(Qt::CTRL + Qt::Key_O);
    acaoSalvar->setShortcut(Qt::CTRL + Qt::Key_S);
    acaoSair->setShortcut(Qt::Key_Q);

    //enviando sinais das acoes para os seus respectivos slots
    connect(acaoSair, SIGNAL(triggered(bool)), this, SLOT(Sair()));
    connect(acaoFacil, SIGNAL(triggered(bool)), this, SLOT(Facil()));
}

void Janela::paintEvent(QPaintEvent *event)
{
    QPainter pintor(this);
    QColor cor(Qt::darkGreen);
    QBrush baldinho(cor);
    pintor.setBrush(baldinho);
    pintor.drawRoundedRect(30,50,600,600,10,10);
}

void Janela::Facil()
{
    Game *game = new Game();
    //game->show();
}

void Janela::Sair()
{
    close();
}

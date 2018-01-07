#include <QApplication>
#include "jeu.h"
#include "home.h"
#include "game.h"

//Jeu *jeu;
Game *game;
Home *home;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

/*
    jeu = new Jeu();
    jeu->show();
    jeu->start();*/
/*
    home = new Home();
    home->show();
    */

    game = new Game();
    game->show();
    game->start();

    return app.exec();
}

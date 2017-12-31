#include <QApplication>
#include "jeu.h"

Jeu *jeu;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    jeu = new Jeu();
    jeu->show();
    jeu->start();
    return app.exec();
}

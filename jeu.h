#ifndef JEU_H
#define JEU_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "case.h"
#include "plateau.h"
#include "chrominounicolore.h"
#include "chrominobicolore.h"
#include "chrominotricolore.h"

class Jeu: public QGraphicsView
{
public:
    Jeu(QWidget* parent=NULL);
    /*
    static int getMaxChromino();
    static int getMaxChrominoTricolore();
    static int getMaxChrominoBicolore();
    static int getMaxChrominoUnicolore();
    static int getMaxChrominoCameleon();
    */
    void start();

    //public attributes
    QGraphicsScene * scene;
    Plateau * plateau;
    QString whosTurn;

/*
private:
    static int const maxChromino;
    static int const maxChrominoTricolore;
    static int const maxChrominoBicolore;
    static int const maxChrominoUnicolore;
    static int const maxChrominoCameleon;
    */
};

#endif // JEU_H

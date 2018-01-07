#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>
#include <time.h>
#include <stdlib.h>
#include "case.h"
#include "chromino.h"
#include "chrominounicolore.h"
#include "chrominobicolore.h"
#include "chrominotricolore.h"
#include "joueur.h"
#include "plateau.h"

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

    void start();
    enum Color{BLEU=0,VERT,ROUGE,VIOLET,JAUNE};

private:
    //Variables
    QGraphicsScene * scene;
    QVector<Chromino *> chrominoUnicolores;
    QVector<Chromino *> chrominoBicolores110;
    QVector<Chromino *> chrominoBicolores101;
    QVector<Chromino *> chrominoCameleons;
    QVector<Chromino *> chrominoTricolores;
    QVector<Chromino *> chrominos;
    QVector<Joueur*> joueurs;
    Chromino* currentChromino;

    //Fonctions
    QVector<Case *> genererCases(int nbCouleurs, bool type110, bool type101, bool typeCameleon);
    void genererChromino();//Rempli un QVector de chromino
    void genererChrominoUnicolore();
    void genererChrominoBicolore110();
    void genererChrominoBicolore101();
    void genererChrominoCameleon();
    void genererChrominoTricolore();
    void distribuerChrominoJoueur(QVector<Chromino *> const& ch);
    void remplirSac(QVector<Chromino *>& pioche);
    void initPlateau();
    bool compareVectorCases(QVector<Case *> &a, QVector<Case *> &b);

private slots:
    void on_btn_left_clicked();

    void on_btn_up_clicked();

    void on_btn_right_clicked();

    void on_btn_down_clicked();

    void on_pushButton_clicked();

private:
    Ui::Game *ui;

    void afficherChrominos(QVector<Chromino *> &chromino);



};

#endif // GAME_H

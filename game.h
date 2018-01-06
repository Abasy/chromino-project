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

    //Getters nombre de chromino de chaque type
    static int getMaxChromino();

    static int getMaxChrominoUnicolore();

    static int getMaxChrominoBicolore101();

    static int getMaxChrominoBicolore110();

    static int getMaxChrominoCameleon();

    static int getMaxChrominoTricolore();

private:
    //Variables
    QGraphicsScene * scene;
    QVector<ChrominoUnicolore *> chrominoUnicolors;
    QVector<ChrominoBicolore *> chrominoBicolors110;
    QVector<ChrominoBicolore *> chrominoBicolors101;
    QVector<ChrominoBicolore *> chrominoCameleons;
    QVector<ChrominoTricolore *> chrominoTricolors;
    QVector<Chromino *> chrominos;
    QVector<Joueur*> joueurs;
    Chromino* currentChromino;

    //Fonctions
    QVector<Case *> genererCases(int nbCouleurs, bool type110, bool type101, bool typeCameleon);
    QVector<Chromino *> genererChromino();//Rempli un QVector de chromino
    QVector<ChrominoUnicolore *> genererChrominoUnicolore();
    QVector<ChrominoBicolore *> genererChrominoBicolore110();
    QVector<ChrominoBicolore *> genererChrominoBicolore101();
    QVector<ChrominoBicolore *> genererChrominoCameleon();
    QVector<ChrominoTricolore *> genererChrominoTricolore();
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

    //Variable static global
    static int maxChromino;
    static int maxChrominoUnicolore;
    static int maxChrominoBicolore101;
    static int maxChrominoBicolore110;
    static int maxChrominoCameleon;
    static int maxChrominoTricolore;



};

#endif // GAME_H

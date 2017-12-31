#include "jeu.h"

/*
int const maxChromino(80);
int const maxChrominoTricolore(30);
int const maxChrominoBicolore(40);
int const maxChrominoUnicolore(5);
int const maxChrominoCameleon(5);
*/

Jeu::Jeu(QWidget *parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 680);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,680);
    setScene(scene);
}

void Jeu::start(){
    //test code todo remove
    QPixmap pix(":/Images/chromino_rouge.png");
    Case *maCase = new Case(pix);
    /*Case *case1(new QPixmap(":/Images/chromino_rouge.png"));
    Case *case2(new QPixmap(":/Images/chromino_bleu.png"));
    Case *case3(new QPixmap(":/Images/chromino_vert.png"));

    ChrominoUnicolore* unicolore = new ChrominoUnicolore(case1, case1, case1);
    ChrominoBicolore* bicolore = new ChrominoBicolore(case2, case2, case3);
    ChrominoTricolore* tricolore = new ChrominoTricolore(case1, case2, case3);

    scene->addItem(unicolore);
    scene->addItem(bicolore);
    scene->addItem(tricolore);

    unicolore->rotateChromino();
    bicolore->rotateChromino();
    tricolore->rotateChromino();
*/
    scene->addItem(maCase);
}

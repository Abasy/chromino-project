#include "jeu.h"
#include <QPushButton>

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
    /*QPushButton* btn = new QPushButton();
    scene->addItem(btn);
    btn->move(50,70);*/

    QPixmap pix(":/Images/chromino_rouge.png");
    QPixmap pix2(":/Images/chromino_bleu.png");
    QPixmap pix3(":/Images/chromino_vert.png");
/*
    //Unicolore
    Case *caseu1 = new Case(pix,1,0,0);
    Case *caseu2 = new Case(pix,1,15,0);
    Case *caseu3 = new Case(pix,1,30,0);
*/
    //Bicolore
    Case *caseb1 = new Case(pix2,2,0,30);
    Case *caseb2 = new Case(pix2,2,15,30);
    Case *caseb3 = new Case(pix3,3,30,30);
/*
    //Tricolore
    Case *caset1 = new Case(pix,2,0,30);
    Case *caset2 = new Case(pix2,2,15,30);
    Case *caset3 = new Case(pix3,3,30,30);
*/
    //ChrominoUnicolore* unicolore = new ChrominoUnicolore(caseu1, caseu2, caseu3);
    ChrominoBicolore* bicolore = new ChrominoBicolore(caseb1, caseb2, caseb3);
    //ChrominoTricolore* tricolore = new ChrominoTricolore(case1, case2, case3);

    //qDebug()<< "Nombre de chromino unicolore"<<bicolore->getNombre_chrominos_bicolore();

    scene->addItem(bicolore);
    //scene->addItem(unicolore);
    //scene->addItem(tricolore);

    //connect(btn,SIGNAL(clicked(bool)),bicolore,SIGNAL(bicolore->rotateChromino());


    //unicolore->rotateChromino();
    /*bicolore->setPos(45,30);

    bicolore->rotateChromino();
    bicolore->rotateChromino();*/
    //tricolore->rotateChromino(0);
}

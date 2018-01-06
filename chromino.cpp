#include "chromino.h"

using namespace std;
int Chromino::nombre_chrominos(0);

Chromino::Chromino(Case* case1,
                   Case* case2,
                   Case* case3,
                   QGraphicsItem *parent)
    :QGraphicsItemGroup(),
    posX(case1->getPosX()),posY(case1->getPosY()),isUse(false)
{
    nombre_chrominos++;
    //idChromino = nombre_chrominos;

    qDebug()<<"Création d'un chromino";
    //createChromino(chromino);
    //setHandlesChildEvents(false);
    qDebug()<<"Nombre de chromino : "<<nombre_chrominos;
}

Chromino::~Chromino()
{
    nombre_chrominos--;
}

int Chromino::getNombre_chrominos(){return nombre_chrominos;}


bool Chromino::getIsUse() const
{
    return isUse;
}

QVector<Case *> Chromino::getChromino() const
{
    return chromino;
}

void Chromino::setChromino(const QVector<Case *> &value)
{
    chromino = value;
}

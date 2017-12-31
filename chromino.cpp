#include "chromino.h"

using namespace std;
int Chromino::nombre_chrominos(0);

Chromino::Chromino(QGraphicsItem *parent)
    :QGraphicsItemGroup()
{
    nombre_chrominos++;
    idChromino = nombre_chrominos;
}

Chromino::~Chromino()
{
    nombre_chrominos--;
}

int Chromino::getNombre_chrominos()
{
    return nombre_chrominos;
}


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

void Chromino::rotateChromino(qreal pos)
{
    int angle = static_cast<int>(45*pos);
    if(_front)
        angle += 45;

    QTransform transform;
    transform.translate(100,0);
    transform.rotate(angle, Qt::YAxis);
    transform.translate(-100,0);
    setTransform(transform);

    if(pos == 1.0)
        _front = !_front;
}


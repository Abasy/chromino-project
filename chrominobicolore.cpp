#include "chrominobicolore.h"

using namespace std;
int ChrominoBicolore::nombre_chrominos_bicolore(0);

ChrominoBicolore::ChrominoBicolore(Case *case1,
                                   Case *case2,
                                   Case *case3,
                                   QGraphicsItem *parent)
    :Chromino(parent), _front(true)/*, _timeLine(0)*/
{
    nombre_chrominos_bicolore++;
    idChrominoBicolore = nombre_chrominos_bicolore;
    chrominoBicolore.push_back(case1);
    chrominoBicolore.push_back(case2);
    chrominoBicolore.push_back(case3);

    createChromino(chrominoBicolore);
    //createBackChromino(_caseVide);
    setHandlesChildEvents(false);
}

ChrominoBicolore::~ChrominoBicolore()
{
    nombre_chrominos_bicolore--;
}

int ChrominoBicolore::getNombre_chrominos_bicolore(){return nombre_chrominos_bicolore;}
int ChrominoBicolore::getIdChrominoBicolore() const{return idChrominoBicolore;}

QVector<Case*> ChrominoBicolore::getChrominoBicolore() const
{
    return chrominoBicolore;
}

void ChrominoBicolore::setChrominoBicolore(const QVector<Case*> &value)
{
    chrominoBicolore = value;
}

void ChrominoBicolore::rotateChromino(qreal pos)
{
    Chromino::rotateChromino(pos);
    /*
    int angle = static_cast<int>(45*pos);
    if(_front)
        angle += 45;

    QTransform transform;
    transform.translate(100,0);
    transform.rotate(angle, Qt::YAxis);
    transform.translate(-100,0);
    setTransform(transform);

    if(pos == 1.0)
        _front = !_front;*/
}

void ChrominoBicolore::createChromino(const QVector<Case*> &chromino)
{
    addToGroup(chromino[0]);
    addToGroup(chromino[1]);
    addToGroup(chromino[2]);
}

/*
void ChrominoUnicolore::createBackChromino(const Case &backChromino)
{
    vector<Case> tmp_vector = new vector<Case>(3,backChromino);
    _configChromino = new QGraphicsProxyWidget();
    _configChromino->setWidget(createChrominoVide(tmp_vector));
    addToGroup(_configChromino);
    _configChromino->hide();
}

void ChrominoUnicolore::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{

}
*/

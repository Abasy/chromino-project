#include "chrominounicolore.h"

using namespace std;
int ChrominoUnicolore::nombre_chrominos_unicolore(0);

ChrominoUnicolore::ChrominoUnicolore(Case* case1,
                                     Case* case2,
                                     Case* case3,
                                     QGraphicsItem *parent)
    : Chromino(parent), _front(true)/*, _timeLine(0), _caseVide(new QPixmap(":/Images/chromino_back.png"))*/
{
    nombre_chrominos_unicolore++;
    idChrominoUnicolore = nombre_chrominos_unicolore;
    chrominoUnicolore.push_back(case1);
    chrominoUnicolore.push_back(case2);
    chrominoUnicolore.push_back(case3);

    createChromino(chrominoUnicolore);
    //createBackChromino(_caseVide);
    setHandlesChildEvents(false);
}

ChrominoUnicolore::~ChrominoUnicolore()
{
    nombre_chrominos_unicolore--;
}

int ChrominoUnicolore::getNombre_chrominos_unicolore(){return nombre_chrominos_unicolore;}
int ChrominoUnicolore::getIdChrominoUnicolore() const{return idChrominoUnicolore;}

QVector<Case*> ChrominoUnicolore::getChrominoUnicolore() const
{
    return chrominoUnicolore;
}

void ChrominoUnicolore::setChrominoUnicolore(const QVector<Case*> &value)
{
    chrominoUnicolore = value;
}

void ChrominoUnicolore::rotateChromino(qreal pos)
{
    Chromino::rotateChromino(pos);
    /*int angle = static_cast<int>(45*pos);
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

void ChrominoUnicolore::createChromino(QVector<Case*> const& chromino)
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

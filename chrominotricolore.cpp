#include "chrominotricolore.h"

using namespace std;
int ChrominoTricolore::nombre_chrominos_tricolore(0);

ChrominoTricolore::ChrominoTricolore(Case *case1,
                                     Case *case2,
                                     Case *case3,
                                     QGraphicsItem *parent)
    : Chromino(parent), _front(true)
{
    nombre_chrominos_tricolore++;
    idChrominoTricolore = nombre_chrominos_tricolore;
    chrominoTricolore.push_back(*case1);
    chrominoTricolore.push_back(*case2);
    chrominoTricolore.push_back(*case3);
}

ChrominoTricolore::~ChrominoTricolore()
{
    nombre_chrominos_tricolore--;

    for(vector< Case >::iterator it = chrominoTricolore.begin() ;it != chrominoTricolore.end(); ++it)
    {
        delete (*it);  //On libère la i-ème case mémoire allouée
    }
    chrominoTricolore.clear();
}

int ChrominoTricolore::getNombre_chrominos_tricolore(){return nombre_chrominos_tricolore;}
int ChrominoTricolore::getIdChrominoTricolore() const{return idChrominoTricolore;}

std::vector<Case> ChrominoTricolore::getChrominoTricolore() const
{
    return chrominoTricolore;
}

void ChrominoTricolore::setChrominoTricolore(const std::vector<Case> &value)
{
    chrominoTricolore = value;
}

void ChrominoTricolore::rotateChromino(qreal pos)
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

void ChrominoTricolore::createChromino(const std::vector<Case> &chromino)
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

#include "chrominobicolore.h"
#include <QDebug>

using namespace std;
int ChrominoBicolore::nombre_chrominos_bicolore(0);

ChrominoBicolore::ChrominoBicolore(QVector<Case *> &cases, QGraphicsItem *parent)
    :Chromino(cases[0],cases[1],cases[2],parent), cases(cases)
{
    nombre_chrominos_bicolore++;
    idChrominoBicolore = nombre_chrominos_bicolore;

    chromino.push_back(cases[0]);
    chromino.push_back(cases[1]);
    chromino.push_back(cases[2]);

    qDebug()<<"Création du chrominoBicolore";
    createChromino(chromino);
    setHandlesChildEvents(false);
    qDebug()<<"Nombre de chrominoBicolore : "<<nombre_chrominos_bicolore;

}

ChrominoBicolore::ChrominoBicolore(Case *case1,
                                   Case *case2,
                                   Case *case3,
                                   QGraphicsItem *parent)
    :Chromino(case1,case2,case3,parent)
{
    nombre_chrominos_bicolore++;
    idChrominoBicolore = nombre_chrominos_bicolore;

    chromino.push_back(case1);
    chromino.push_back(case2);
    chromino.push_back(case3);

    qDebug()<<"Création du chrominoBicolore";
    createChromino(chromino);
    setHandlesChildEvents(false);
    qDebug()<<"Nombre de chrominoBicolore : "<<nombre_chrominos_bicolore;
}

ChrominoBicolore::~ChrominoBicolore()
{
    nombre_chrominos_bicolore--;
}

int ChrominoBicolore::getNombre_chrominos_bicolore(){return nombre_chrominos_bicolore;}

int ChrominoBicolore::getIdChrominoBicolore() const{return idChrominoBicolore;}


void ChrominoBicolore::createChromino(QVector<Case *> &chromino)
{
    for(int i=0 ; i < chromino.size() ; i++) {
        this->addToGroup(chromino.at(i));
    }
}

void ChrominoBicolore::rotateChromino()
{
    switch(_angle){
        case 0: _angle+=90;break;
    case 90 : _angle+=90;break;
    case 180 :_angle+=90;break;
        //case 270 :_angle+=90;break;
        default : _angle=0;
    }
    QPointF offset = this->sceneBoundingRect().center();
    qDebug()<<offset;
    QTransform transform;
    transform.translate(offset.x(),offset.y());
    transform.rotate(_angle);
    transform.translate(-offset.x(),-offset.y());
    this->setTransform(transform);
    qDebug()<<"angle ="<<_angle;
    //Enregistrer les nouvelles coordonnées du chromino
    qDebug()<<"coordonnées ("<<scenePos().x()<<","<<scenePos().y()<<")";

    //Enregistrer les nouvelles coordonnées des cases
    //qDebug()<<"coordonnées ("<<getPosX()<<","<<getPosY()<<")";

}

QVector<Case *> ChrominoBicolore::getCases() const
{
    return cases;
}

void ChrominoBicolore::setCases(const QVector<Case *> &value)
{
    cases = value;
}

/*
bool operator==(Chromino * const &a, Chromino * const &b)
{
    return a->estEgal(b);
}
*/

bool ChrominoBicolore::estEgal(Chromino * const &b) const
{
    bool condition_1(false);
    bool condition_2(false);
    QVector<Case *> vectorChr = b->getChromino();

    //On vérifie le cas où les chrominos sont rangés de la même manière
    if(chromino[0]->getIdCouleur()==vectorChr[0]->getIdCouleur()
       && chromino[1]->getIdCouleur()==vectorChr[1]->getIdCouleur()
            && chromino[2]->getIdCouleur()==vectorChr[2]->getIdCouleur()){
        condition_1=true;
        qDebug()<< "à l'endroit : les chrominos sont identiques";
    }

    //On vérifie le cas où l'un des chrominos est inversé
    if(chromino[0]->getIdCouleur()==vectorChr[2]->getIdCouleur()
       && chromino[1]->getIdCouleur()==vectorChr[1]->getIdCouleur()
       && chromino[2]->getIdCouleur()==vectorChr[0]->getIdCouleur()){
        condition_2 = true;
        qDebug()<< "à l'envers : les chrominos sont identiques";
    }

    return (condition_1 || condition_2);
}

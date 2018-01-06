#include "chrominounicolore.h"

using namespace std;
int ChrominoUnicolore::nombre_chrominos_unicolore(0);

ChrominoUnicolore::ChrominoUnicolore(QVector<Case *> &cases, QGraphicsItem *parent)
    :Chromino(cases[0],cases[1],cases[2],parent), cases(cases)
{
    nombre_chrominos_unicolore++;
    idChrominoUnicolore = nombre_chrominos_unicolore;

    chromino.push_back(cases[0]);
    chromino.push_back(cases[1]);
    chromino.push_back(cases[2]);

    qDebug()<<"Création du chrominoUnicolore";
    createChromino(chromino);
    setHandlesChildEvents(false);
    qDebug()<<"Nombre de chromino unicolor : "<<nombre_chrominos_unicolore;

}

ChrominoUnicolore::ChrominoUnicolore(Case* case1,
                                     Case* case2,
                                     Case* case3,
                                     QGraphicsItem *parent)
    : Chromino(case1,case2,case3,parent)
{
    nombre_chrominos_unicolore++;
    idChrominoUnicolore = nombre_chrominos_unicolore;

    chromino.push_back(case1);
    chromino.push_back(case2);
    chromino.push_back(case3);

    qDebug()<<"Création du chrominoUnicolore";
    createChromino(chromino);
    setHandlesChildEvents(false);
    qDebug()<<"Nombre de chromino unicolor : "<<nombre_chrominos_unicolore;
}

ChrominoUnicolore::~ChrominoUnicolore()
{
    nombre_chrominos_unicolore--;
}

int ChrominoUnicolore::getNombre_chrominos_unicolore(){return nombre_chrominos_unicolore;}
int ChrominoUnicolore::getIdChrominoUnicolore() const{return idChrominoUnicolore;}


void ChrominoUnicolore::createChromino(QVector<Case *> &chromino)
{
    for(int i=0 ; i < chromino.size() ; i++) {
        this->addToGroup(chromino.at(i));
    }
}

void ChrominoUnicolore::rotateChromino()
{
    switch(_angle){
        case 0: _angle+=90;break;
        case 90 : _angle+=90;break;
        case 180 :_angle+=90;break;
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

QVector<Case *> ChrominoUnicolore::getCases() const
{
    return cases;
}

void ChrominoUnicolore::setCases(const QVector<Case *> &value)
{
    cases = value;
}

/*
bool ChrominoUnicolore::operator==(Chromino * const &chr)
{
    return this->estEgal(chr);
}
*/
bool ChrominoUnicolore::estEgal(Chromino * const &b) const
{
    bool condition_1(false);
    bool condition_2(false);
    QVector<Case *> vectorChr = b->getChromino();

    //On vérifie le cas où les chrominos sont rangés de la même manière
    if(chromino[0]->getIdCouleur()==vectorChr[0]->getIdCouleur()
       && chromino[1]->getIdCouleur()==vectorChr[1]->getIdCouleur()
            && chromino[2]->getIdCouleur()==vectorChr[2]->getIdCouleur()){
        condition_1=true;
        qDebug()<< "les chrominos sont identiques";
    }

    //On vérifie le cas où l'un des chrominos est inversé
    if(chromino[0]->getIdCouleur()==vectorChr[2]->getIdCouleur()
       && chromino[1]->getIdCouleur()==vectorChr[1]->getIdCouleur()
       && chromino[2]->getIdCouleur()==vectorChr[0]->getIdCouleur()){
        condition_2 = true;
        qDebug()<< "les chrominos sont identiques";
    }

    return (condition_1 || condition_2);
}

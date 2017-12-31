#include "case.h"

Case::Case(QPixmap &pix, QGraphicsItem* parent):pixmap(pix)
{
    setPixmap(pixmap);
}

QPixmap Case::getPixmap() const
{
    return pixmap;
}

void Case::setPixmap(const QPixmap &value)
{
    pixmap = value;
}

int Case::getIdCouleur() const
{
    return idCouleur;
}

void Case::setIdCouleur(int value)
{
    idCouleur = value;
}

/*
Case::Case(QGraphicsItem *parent){
    //Desiner une case
    //On a besoin de 4 points (1,0)(2,0)(1,1)(2,1)
    QVector<QPointF> casePoints;
    casePoints << QPointF(1,0) << QPointF(2,0)
              << QPointF(2,1) << QPointF(1,1);

    //scale les points
    int SCALE_BY = 15;
    for(size_t i=0, n = casePoints.size();i<n;++i){
        casePoints[i] *= SCALE_BY;
    }

    //Créer un carré avec les points
    QPolygonF carre(casePoints);

    //Dessiner le carré
    setPolygon(carre);
}
*/

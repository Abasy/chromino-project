#include "case.h"

Case::Case(QPixmap pix, int couleur,
           qreal pX, qreal pY,
           qreal w, qreal h,
           QGraphicsItem* parent)
    :QGraphicsPixmapItem(), pixmap(pix), idCouleur(couleur),
      posX(pX),posY(pY), width(w), height(h)
{
    //qDebug() << "Création de la case" << QString(idCouleur);
    setPos(posX,posY);
    setPixmap(pixmap);

}
/*
QPixmap Case::getPixmap() const
{
    return pixmap;
}

void Case::setPixmap(const QPixmap &value)
{
    pixmap = value;
}
*/
int Case::getIdCouleur() const
{
    return idCouleur;
}

void Case::setIdCouleur(int value)
{
    idCouleur = value;
}

qreal Case::getWidth() const
{
    return width;
}

void Case::setWidth(const qreal &value)
{
    width = value;
}

qreal Case::getHeight() const
{
    return height;
}

void Case::setHeight(const qreal &value)
{
    height = value;
}

qreal Case::getPosX() const
{
    return posX;
}

void Case::setPosX(const qreal &value)
{
    posX = value;
}

qreal Case::getPosY() const
{
    return posY;
}

void Case::setPosY(const qreal &value)
{
    posY = value;
}

void Case::setPosCase()
{
    QPointF offset = this->sceneBoundingRect().center();
    setPosX(offset.x());
    setPosY(offset.y());
}

QRectF Case::boundingRect() const
{
    return QRectF(posX,posY,width,height);
}


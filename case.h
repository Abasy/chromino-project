#ifndef CASE_H
#define CASE_H
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QRectF>

class Case: public QGraphicsPixmapItem
{
public:
    //constructeur
    Case(QPixmap pix, int couleur=0,
         qreal pX=0, qreal pY=0,
         qreal w=0, qreal h=0,
         QGraphicsItem *parent=Q_NULLPTR);
/*
    QPixmap getPixmap() const;
    void setPixmap(const QPixmap &value);
*/
    int getIdCouleur() const;
    void setIdCouleur(int value);

    qreal getWidth() const;
    void setWidth(const qreal &value);

    qreal getHeight() const;
    void setHeight(const qreal &value);

    qreal getPosX() const;
    void setPosX(const qreal &value);

    qreal getPosY() const;
    void setPosY(const qreal &value);
public slots:
    void setPosCase();

private:
    QPixmap pixmap;
    int idCouleur=0;
    qreal posX;
    qreal posY;
    qreal width;
    qreal height;
    QRectF boundingRect()const;
};
#endif // CASE_H

#ifndef CHROMINO_H
#define CHROMINO_H
#include <QDebug>
#include "case.h"
#include <QVector>
#include <QRectF>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Chromino: public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Chromino(Case* case1,
             Case* case2,
             Case* case3,
             QGraphicsItem *parent=Q_NULLPTR);
    virtual ~Chromino();
    static int getNombre_chrominos();

    qreal getPosX() const;
    //void setPosX(const qreal &value);

    qreal getPosY() const;
    //void setPosY(const qreal &value);

    bool getIsUse() const;
    //void setIsUse(bool value);

    QVector<Case *> getChromino() const;
    void setChromino(const QVector<Case *> &value);

    //Surcharge d'operateur
    bool operator==(Chromino * const& b);
    bool estEgal(Chromino* const& b) const;

protected:
    //Variable
    //int idChromino;
    static int nombre_chrominos;
    qreal posX;
    qreal posY;
    QVector<Case *> chromino;
    int _angle;
    bool isUse;
};

#endif // CHROMINO_H

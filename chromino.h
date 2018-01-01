#ifndef CHROMINO_H
#define CHROMINO_H
#include "case.h"
#include <QVector>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Chromino: public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Chromino(QGraphicsItem *parent=Q_NULLPTR);
    virtual ~Chromino();
    int getIdChromino() const;
    static int getNombre_chrominos();

public slots:
    virtual void rotateChromino(qreal pos);

protected:
    //GUI
    bool _front;
    //QGraphicsPixmapItem* _caseVide;
    //QTimeLine* _timeLine;
    //QGraphicsProxyWidget* _configChromino;

    //Variable
    int idChromino;
    static int nombre_chrominos;

    //Fonction
    virtual void createChromino(QVector<Case*> const& chromino) const;
    //void createBackChromino(const Case& backChromino);

    //Event
    //void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    //void moveChromino();

    //virtual void createChromino(int const& nbCouleur) const;
};

#endif // CHROMINO_H

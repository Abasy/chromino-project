#ifndef CHROMINO_H
#define CHROMINO_H
#include "case.h"
#include <vector>
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

private slots:
    virtual void rotateChromino() const;

protected:
    int idChromino;
    static int nombre_chrominos;

    virtual void createChromino() const;
};

#endif // CHROMINO_H

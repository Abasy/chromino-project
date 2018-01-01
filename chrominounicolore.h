#ifndef CHROMINOUNICOLORE_H
#define CHROMINOUNICOLORE_H
#include "chromino.h"
#include <QTimeLine>
#include <QGraphicsProxyWidget>
#include <QVector>

class ChrominoUnicolore : public Chromino
{
public:
    ChrominoUnicolore(Case* case1,
                      Case* case2,
                      Case* case3,
                      QGraphicsItem *parent=Q_NULLPTR);
    virtual ~ChrominoUnicolore();
    int getIdChrominoUnicolore() const;
    static int getNombre_chrominos_unicolore();

    QVector<Case*> getChrominoUnicolore() const;
    void setChrominoUnicolore(const QVector<Case*> &value);

private slots:
    void rotateChromino(qreal pos);

protected:
    //GUI
    bool _front;
    //QGraphicsPixmapItem* _caseVide;
    //QTimeLine* _timeLine;
    //QGraphicsProxyWidget* _configChromino;

    //Variable
    int idChrominoUnicolore;
    static int nombre_chrominos_unicolore;
    QVector<Case*> chrominoUnicolore;

    //Fonction
    void createChromino(QVector<Case*> const& chromino);
    //void createBackChromino(const Case& backChromino);

    //Event
    //void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    //void moveChromino();
};

#endif // CHROMINOUNICOLORE_H

#ifndef CHROMINOUNICOLORE_H
#define CHROMINOUNICOLORE_H
#include "chromino.h"
#include <QTimeLine>
#include <QGraphicsProxyWidget>

class ChrominoUnicolore : public Chromino
{
public:
    ChrominoUnicolore(Case const* case1,
                      Case const* case2,
                      Case const* case3,
                      QGraphicsItem *parent=Q_NULLPTR);
    virtual ~ChrominoUnicolore();
    int getIdChrominoUnicolore() const;
    static int getNombre_chrominos_unicolore();

    std::vector<Case> getChrominoUnicolore() const;
    void setChrominoUnicolore(const std::vector<Case> &value);

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
    std::vector<Case> chrominoUnicolore;

    //Fonction
    void createChromino(std::vector<Case> const& chromino);
    //void createBackChromino(const Case& backChromino);

    //Event
    //void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    //void moveChromino();
};

#endif // CHROMINOUNICOLORE_H

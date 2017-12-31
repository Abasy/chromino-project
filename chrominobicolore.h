#ifndef CHROMINOBICOLORE_H
#define CHROMINOBICOLORE_H
#include "chromino.h"
#include <QTimeLine>
#include <QGraphicsProxyWidget>

class ChrominoBicolore: public Chromino
{
public:
    ChrominoBicolore(Case *case1,
                     Case *case2,
                     Case *case3,
                     QGraphicsItem *parent=Q_NULLPTR);
    virtual ~ChrominoBicolore();
    int getIdChrominoBicolore() const;
    static int getNombre_chrominos_bicolore();

    std::vector<Case> getChrominoBicolore() const;
    void setChrominoBicolore(const std::vector<Case> &value);

private slots:
    void rotateChromino(qreal pos);

protected:
    //GUI
    bool _front;
    //QGraphicsPixmapItem* _caseVide;
    //QTimeLine* _timeLine;
    //QGraphicsProxyWidget* _configChromino;

    //Variable
    int idChrominoBicolore;
    static int nombre_chrominos_bicolore;
    std::vector<Case> chrominoBicolore;

    //Fonction
    void createChromino(std::vector<Case> const& chromino);
    //void createBackChromino(const Case& backChromino);

    //Event
    //void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    //void moveChromino();
};

#endif // CHROMINOBICOLORE_H

#ifndef CHROMINOTRICOLORE_H
#define CHROMINOTRICOLORE_H
#include "chromino.h"

class ChrominoTricolore: public Chromino
{
public:
    ChrominoTricolore(Case *case1,
                      Case *case2,
                      Case *case3,
                      QGraphicsItem *parent=Q_NULLPTR);
    virtual ~ChrominoTricolore();
    int getIdChrominoTricolore() const;
    static int getNombre_chrominos_tricolore();

    std::vector<Case> getChrominoTricolore() const;
    void setChrominoTricolore(const std::vector<Case> &value);

private slots:
    void rotateChromino(qreal pos);

protected:
    //GUI
    bool _front;
    //QGraphicsPixmapItem* _caseVide;
    //QTimeLine* _timeLine;
    //QGraphicsProxyWidget* _configChromino;

    //Variable
    int idChrominoTricolore;
    static int nombre_chrominos_tricolore;
    std::vector<Case> chrominoTricolore;

    //Fonction
    void createChromino(std::vector<Case> const& chromino);
    //void createBackChromino(const Case& backChromino);

    //Event
    //void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    //void moveChromino();
};

#endif // CHROMINOTRICOLORE_H

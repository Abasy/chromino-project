#ifndef CHROMINOTRICOLORE_H
#define CHROMINOTRICOLORE_H
#include "chromino.h"

class ChrominoTricolore: public Chromino
{
public:
    ChrominoTricolore(QVector<Case *> &cases,
                     QGraphicsItem *parent=Q_NULLPTR);

    ChrominoTricolore(Case *case1,
                      Case *case2,
                      Case *case3,
                      QGraphicsItem *parent=Q_NULLPTR);
    virtual ~ChrominoTricolore();
    int getIdChrominoTricolore() const;
    static int getNombre_chrominos_tricolore();

    //Surcharge d'operateur
    //bool operator==(Chromino* const& b);
    bool estEgal(Chromino* const& b) const;

    //Fonctions
    void afficherChromino() const;

public slots:
    void rotateChromino();

protected:
    //Variable
    int idChrominoTricolore;
    static int nombre_chrominos_tricolore;

    //Fonction
    void createChromino(QVector<Case *>& chromino);
};

#endif // CHROMINOTRICOLORE_H

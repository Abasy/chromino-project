#ifndef CHROMINOBICOLORE_H
#define CHROMINOBICOLORE_H
#include "chromino.h"

class ChrominoBicolore: public Chromino
{
public:
    ChrominoBicolore(QVector<Case *> &cases,
                     QGraphicsItem *parent=Q_NULLPTR);
    ChrominoBicolore(Case* case1,
                     Case* case2,
                     Case* case3,
                     QGraphicsItem *parent=Q_NULLPTR);
    virtual ~ChrominoBicolore();
    int getIdChrominoBicolore() const;
    static int getNombre_chrominos_bicolore();

    //Surcharge d'operateur
    //bool operator==(Chromino * const& b);
    bool estEgal(Chromino* const& b) const;

    //Fonctions
    void afficherChromino() const;

public slots:
    void rotateChromino();

protected:
    //Variable
    int idChrominoBicolore;
    static int nombre_chrominos_bicolore;

    //Fonction
    void createChromino(QVector<Case *>& chromino);
};
#endif // CHROMINOBICOLORE_H

#ifndef CHROMINOUNICOLORE_H
#define CHROMINOUNICOLORE_H
#include "chromino.h"

class ChrominoUnicolore : public Chromino
{
public:
    ChrominoUnicolore(QVector<Case *> &cases,
                     QGraphicsItem *parent=Q_NULLPTR);

    ChrominoUnicolore(Case* case1,
                      Case* case2,
                      Case* case3,
                      QGraphicsItem *parent=Q_NULLPTR);
    virtual ~ChrominoUnicolore();
    int getIdChrominoUnicolore() const;
    static int getNombre_chrominos_unicolore();

    //Surcharge d'operateur
    //bool operator==(Chromino* const& b);
    bool estEgal(Chromino* const& b) const;

    //Fonctions
    void afficherChromino() const;

public slots:
    void rotateChromino();

protected:
    //Variable
    int idChrominoUnicolore;
    static int nombre_chrominos_unicolore;
    //QVector<Case *> cases;

    //Fonction
    void createChromino(QVector<Case *>& chromino);


};

#endif // CHROMINOUNICOLORE_H

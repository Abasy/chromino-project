#ifndef PLATEAU_H
#define PLATEAU_H
#include "case.h"

class Plateau
{
public:
    Plateau();
    QList<Case *> getCases() const;
    void positionCases();

private:
    void creerCaseColonne(int x, int y, int numLignes);
    QList<Case *> cases;
};

#endif // PLATEAU_H

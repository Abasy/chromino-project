#include "plateau.h"
#include "jeu.h"

extern Jeu* jeu;

Plateau::Plateau()
{

}
/*
QList<Case *> Plateau::getCases() const
{
    return cases;
}

void Plateau::positionCases()
{
    creerCaseColonne(100,100,10);
}

void Plateau::creerCaseColonne(int x, int y, int numLignes)
{
    //Crée une colonne de Cases à l'endroit spécidfié
    //avec le nombre de ligne spécifier

    for(size_t i = 0, n=numLignes;i<n;i++){
        Case* currentCase = new Case(new QPixmap);
        currentCase->setPos(x,y+60*i);
        cases.append(currentCase);
        jeu->scene->addItem(currentCase);
    }
}*/


/*
int Plateau::getColonnePlateau() const
{return colonnePlateau;}

void Plateau::setColonnePlateau(int value)
{colonnePlateau = value;}

int Plateau::getLignePlateau() const
{return lignePlateau;}

void Plateau::setLignePlateau(int value)
{lignePlateau = value;}

std::vector<std::vector<Case> > Plateau::getMonPlateau() const
{return monPlateau;}

void Plateau::setMonPlateau(const std::vector<std::vector<Case> > &value)
{ monPlateau = value;}

*/

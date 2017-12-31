#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include <string>
#include "chromino.h"
#include <vector>

class Joueur
{
public:
    //Constructeur
    Joueur(std::string nomJoueur);
    Joueur();

    //Destructeur
    //~Joueur();

    //Getters
    std::string getNomJoueur();
    static int nombre_joueurs();
    std::vector<Chromino*> getListChrominos();

private:
    std::string nomJoueur;

    //Liste de 8 chrominos pour le joueur
    std::vector<Chromino*> listChrominos;

    static int nb_joueurs;
};

#endif // JOUEUR_H

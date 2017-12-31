#include "joueur.h"

using namespace std;

int Joueur::nb_joueurs = 0;

Joueur::Joueur(string nom): nomJoueur(nom){
    nb_joueurs++;
    //listChrominos = new vector<Chromino*>(8);
}
Joueur::Joueur():nomJoueur("Joueur") {
    nb_joueurs++;
    string s = to_string(nb_joueurs);
    nomJoueur+=s;
}
string Joueur::getNomJoueur() {return nomJoueur;}
vector<Chromino*> Joueur::getListChrominos() {return listChrominos;}
int Joueur::nombre_joueurs() {return nb_joueurs;}

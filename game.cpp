#include "game.h"
#include "ui_game.h"

const int maxChromino(80);
const int maxChrominoUnicolore(5);
const int maxChrominoBicolore101(20);
const int maxChrominoBicolore110(20);
const int maxChrominoCameleon(5);
const int maxChrominoTricolore(30);

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

Game::~Game()
{
    delete ui;
}

void Game::start()
{
    /*
    QPixmap pix(":/Images/chromino_rouge.png");
    QPixmap pix2(":/Images/chromino_bleu.png");
    QPixmap pix3(":/Images/chromino_vert.png");

    //Bicolore
    Case *caseb1 = new Case(pix2,2,0,30);
    Case *caseb2 = new Case(pix2,2,15,30);
    Case *caseb3 = new Case(pix3,3,30,30);

    //Bicolore2
    Case *caseb4 = new Case(pix2,2,30,30);
    Case *caseb5 = new Case(pix2,2,45,30);
    Case *caseb6 = new Case(pix3,3,60,30);

    ChrominoBicolore* bicolore = new ChrominoBicolore(caseb1, caseb2, caseb3);
    ChrominoBicolore* bicolore2 = new ChrominoBicolore(caseb6, caseb4, caseb5);

    scene->addItem(bicolore);
    scene->update();

    scene->addItem(bicolore2);
    scene->update();
    bicolore->rotateChromino();

    if(bicolore->estEgal(bicolore2)){
        qDebug()<<"C'est les memes";
    }else{
        qDebug()<<"Mince j'ai du rater quelque chose";
    }
*/
    //genererChrominoUnicolore();
    //afficherChrominos(chrominoUnicolores);

    //genererChrominoBicolore110();
    //afficherChrominos(chrominoBicolores110);

    //genererChrominoBicolore101();
    //afficherChrominos(chrominoBicolores101);

    //genererChrominoCameleon();
    //afficherChrominos(chrominoCameleons);

    genererChrominoTricolore();
    afficherChrominos(chrominoTricolores);
}

QVector<Case *> Game::genererCases(int nb_couleurs, bool type110, bool type101, bool typeCameleon)
{
    QVector<Case *> mesCases;
    Case *maCase;
    qreal x, y;
    int couleur(-1);
    QVector<int> vals;
    //On génére la première couleur de la première case
    srand(time(NULL));

    int couleur_tmp = Color(rand()%5);
    //qDebug()<<"Couleur random init"<<couleur;

    if(nb_couleurs==1 || nb_couleurs==3){
        typeCameleon = false;
        type101 = false;
        type110 = false;
    }else{
        if(type101 && type110 && typeCameleon){
            qDebug()<<"Erreur! Choisissez un type : type101, type110 ou typeChromino";
        }
    }

    //Ressources chromino
    QPixmap pixBleu(":/Images/chromino_bleu.png");
    QPixmap pixVert(":/Images/chromino_vert.png");
    QPixmap pixRouge(":/Images/chromino_rouge.png");
    QPixmap pixViolet(":/Images/chromino_violet.png");
    QPixmap pixJaune(":/Images/chromino_jaune.png");
    QPixmap pixCameleon(":/Images/chromino_cameleon.png");

    if(nb_couleurs>0 && nb_couleurs<4){
        for(int i(0);i<3;i++){//On veut générer 3 cases
            //On positionne les cases côte à côte
            switch (i) {
                case 0: x=0; y=0; break;
                case 1:x=15; y=0; break;
                case 2: x=30; y=0; break;
            default: qDebug()<<"Mince! Erreur position!";
                break;
            }

            //Selon le nombres de couleurs
            //générer une, deux ou trois fois la couleur
            switch(nb_couleurs){
                case 1: //Chromino à une seul couleur
                    //On initialise la couleur et on ne le change plus
                    couleur = couleur_tmp;
                    //qDebug()<<"Couleur random1Couleur "<<couleur;
                    break;
                case 2://Les deux première cases sont identiques
                    couleur = couleur_tmp;
                    vals.push_back(couleur);

                    //Chromino 110
                    if(type110 && i>1){
                        while(vals.contains(couleur)){
                            couleur = Color(rand()%5);
                        }
                        //couleur = couleur_tmp;
                        //qDebug()<<"Couleur random type110 "<<couleur;
                    }

                    //Chromino 101
                    if(type101 && i==1){
                        couleur_tmp = couleur;
                        while(vals.contains(couleur)){
                            couleur = Color(rand()%5);
                        }
                        //couleur = couleur_tmp;
                        //qDebug()<<"Couleur random type101 "<<couleur;
                    }
                    if(type101 && i==2){
                        //couleur = couleur_tmp;
                        qDebug()<<"Couleur (random) type101 "<<couleur;
                    }

                    //Chromino Cameleon
                    //si on veut créer un chromino caméléon
                    //on change les couleurs aux extrémités
                    //pour qu'il soit unique
                    if(typeCameleon && (i==1)){
                        couleur_tmp = couleur;//On stock la première couleur
                        couleur = 5;
                        //qDebug()<<"Couleur random Cameleon "<<couleur;
                    }
                    if(typeCameleon && i==2){

                        while(vals[0]==couleur){
                            couleur = Color(rand()%5);
                        }
                        //couleur = couleur_tmp;
                        //qDebug()<<"Couleur random Cameleon "<<couleur;
                    }
                    break;
                case 3:
                    //On change de couleur pour tout les cases
                    couleur = couleur_tmp;
                    vals.push_back(couleur);

                    //Verifier que la couleur n'existe pas déjà
                    if(i>=1){
                        while(vals.contains(couleur)){
                            couleur = Color(rand()%5);
                        }
                        //couleur = couleur_tmp;
                        //qDebug()<<"Couleur random3Couleur "<<couleur;
                    }
                    break;
                default: qDebug()<<"Erreur nb_couleurs!";break;
            }

            //On attribut la couleur à la case
            switch(couleur){
                case 0:
                    //qDebug()<<"Bleu(0)"<<couleur;
                    maCase = new Case(pixBleu,couleur,x,y);
                    mesCases.push_back(maCase);
                    break;//BLEU
                case 1 :
                    //qDebug()<<"Vert(1):"<<couleur;
                    maCase = new Case(pixVert,couleur,x,y);
                    mesCases.push_back(maCase);
                    break;//VERT
                case 2 :
                    //qDebug()<<"Rouge(2):"<<couleur;
                    maCase = new Case(pixRouge,couleur,x,y);
                    mesCases.push_back(maCase);
                    break;//ROUGE
                case 3 :
                    //qDebug()<<"Violet(3):"<<couleur;
                    maCase = new Case(pixViolet,couleur,x,y);
                    mesCases.push_back(maCase);
                    break;//VIOLET
                case 4 :
                    //qDebug()<<"Jaune(4):"<<couleur;
                    maCase = new Case(pixJaune,couleur,x,y);
                    mesCases.push_back(maCase);
                    break;//JAUNE
                case 5 :
                    //qDebug()<<"Cameleon(5):"<<couleur;
                    maCase = new Case(pixCameleon,couleur,x,y);
                    mesCases.push_back(maCase);
                    break;//Cameleon
                default : qDebug()<<"Erreur! Couleur inexistant!";break;
            }
        }
    }else{
        qDebug()<<"Nombre de cases Erroné.\n Choisissez 1,2 ou 3";
    }
    return mesCases;
}

bool Game::compareVectorCases(QVector<Case *> &a, QVector<Case *> &b)
{
    bool condition_1(false);
    bool condition_2(false);

    //On vérifie le cas où les chrominos sont rangés de la même manière
    if(a[0]->getIdCouleur()==b[0]->getIdCouleur()
       && a[1]->getIdCouleur()==b[1]->getIdCouleur()
            && a[2]->getIdCouleur()==b[2]->getIdCouleur()){
        condition_1=true;
        //qDebug()<< "1 chromino à l'endroit : les chrominos sont identiques";
    }

    //On vérifie le cas où l'un des chrominos est inversé
    if(a[0]->getIdCouleur()==b[2]->getIdCouleur()
       && a[1]->getIdCouleur()==b[1]->getIdCouleur()
       && a[2]->getIdCouleur()==b[0]->getIdCouleur()){
        condition_2 = true;
        //qDebug()<< "1 chromino à l'envers : les chrominos sont identiques";
    }

    return (condition_1 || condition_2);
}

void Game::afficherChrominos(QVector<Chromino *> &chromino)
{
    qDebug()<<"Nombre d'élement : "<<chromino.size();
    for(int i(0);i<chromino.size();i++){
        qDebug()<<"-----------Chrominos bicolore : "<<i;
        chromino[i]->afficherChromino();
    }
}

/**
 * @brief Game::genererChromino
 */
void Game::genererChromino()
{
    /*
    genererChrominoUnicolore();
    genererChrominoBicolore101();
    genererChrominoBicolore110();
    genererChrominoCameleon();
    genererChrominoTricolore();

    chrominos.insert(chrominos.end(),chrominoUnicolors);
    chrominos.insert(chrominos.end(),chrominoBicolors101);
    chrominos.insert(chrominos.end(),chrominoBicolors110);
    chrominos.insert(chrominos.end(),chrominoCameleons);
    chrominos.insert(chrominos.end(),chrominoTricolors);*/
}

/**
 * @brief Game::genererChrominoUnicolore
 * Génére 5 chrominos unicolore.
 * Exemple : bleu-bleu-bleu, rouge-rouge-rouge ...etc
 */
void Game::genererChrominoUnicolore()
{
    QVector<Case *> monVecteur(0);
    Case *maCase;
    ChrominoUnicolore *chromino_unicolore;
    qreal x, y;

    //qDebug()<<"ChrominoUnicolore max : "<<maxChrominoUnicolore;

    //Ressources chromino
    QPixmap pixBleu(":/Images/chromino_bleu.png");
    QPixmap pixVert(":/Images/chromino_vert.png");
    QPixmap pixRouge(":/Images/chromino_rouge.png");
    QPixmap pixViolet(":/Images/chromino_violet.png");
    QPixmap pixJaune(":/Images/chromino_jaune.png");

    for(int i(0);i<maxChrominoUnicolore;i++){
        for(int j(0);j<3;j++){
            //On positionne les cases côte à côte
            switch (j) {
                case 0: x= 0; y=0; break;
                case 1: x=15; y=0; break;
                case 2: x=30; y=0; break;
            default: qDebug()<<"Mince! Erreur position!";
                break;
            }

            switch(i){
                case 0:
                    maCase = new Case(pixBleu,i,x,y);
                    monVecteur.push_back(maCase);
                    break;//BLEU
                case 1 :
                    maCase = new Case(pixVert,i,x,y);
                    monVecteur.push_back(maCase);
                    break;//VERT
                case 2 :
                    maCase = new Case(pixRouge,i,x,y);
                    monVecteur.push_back(maCase);
                    break;//ROUGE
                case 3 :
                    maCase = new Case(pixViolet,i,x,y);
                    monVecteur.push_back(maCase);
                    break;//VIOLET
                case 4 :
                    maCase = new Case(pixJaune,i,x,y);
                    monVecteur.push_back(maCase);
                    break;//JAUNE
                default : qDebug()<<"Erreur! Couleur inexistant!";break;
            }
        }
        chromino_unicolore = new ChrominoUnicolore(monVecteur);
        chrominoUnicolores.push_back(chromino_unicolore);

        monVecteur.clear();
    }
}

/**
 * @brief Game::genererChrominoBicolore110
 * Génére 20 chromino bicolore du type110
 * Exemple : vert-vert-rouge ou bleu-bleu-rouge
 */
void Game::genererChrominoBicolore110()
{
    QVector<Case *> monVecteur(0);
    Chromino *chromino_bicolore_110;

    int j(0);
    int cpt(0);

    //On génére 3 cases de type110. Exemple : bleu bleu vert et on enregistre
    //le premier chrominoBicolore de type 110
    /*if(i==0){*/
    qDebug()<<"\n 0ième chromino--------------------";
    monVecteur = genererCases(2,true,false,false);
    chromino_bicolore_110 = new ChrominoBicolore(monVecteur);
    chrominoBicolores110.push_back(chromino_bicolore_110);
    //}*/

    bool identique = false;

    for(int i(1); i<maxChrominoBicolore110; i++){//on boucle 20 fois
        identique = false;//false : Chromino identique pas trouvé
        monVecteur = genererCases(2,true,false,false);

        qDebug()<<"Il y a "<<chrominoBicolores110.size()<<" chrominoBicolores et Trouver = "<<!identique;

        while(j<chrominoBicolores110.size() && !identique){
            QVector<Case *> mesCases = chrominoBicolores110[j]->getChromino();
            identique = compareVectorCases(mesCases, monVecteur);

            qDebug()<<"\n"<<i<<" ième chromino--------------------";
            qDebug()<<"\t"<<j<<"ième different : "<<identique;

            if(identique){//true : Si on a trouver un chromino identique dans la list
                //On recommence avec un nouveau vecteur
                j=0;
                identique = false;
                cpt = 0;
                monVecteur = genererCases(2,true,false,false);
            }else{//false : Si le vecteur n'est pas identique à un chromino de la list
                cpt++;//Le nombre de fois où on a pas trouvé de chromino identique
                j++; //Chromino suivant
            }
        }

        qDebug()<<"CPT = "<<cpt;
        if(cpt==chrominoBicolores110.size()){
            //Le chromino est unique donc on le rajoute dans la liste
            chromino_bicolore_110 = new ChrominoBicolore(monVecteur);
            chrominoBicolores110.push_back(chromino_bicolore_110);
        }
        monVecteur.clear();
    }
}

void Game::genererChrominoBicolore101()
{
    QVector<Case *> monVecteur(0);
    Chromino *chromino_bicolore_101;

    int j(0);
    int cpt(0);

    //On génére 3 cases de type110. Exemple : bleu bleu vert et on enregistre
    //le premier chrominoBicolore de type 110

    qDebug()<<"\n 0 ième chromino--------------------";
    monVecteur = genererCases(2,false,true,false);
    chromino_bicolore_101 = new ChrominoBicolore(monVecteur);
    chrominoBicolores101.push_back(chromino_bicolore_101);

    bool identique = false;

    for(int i(1); i<maxChrominoBicolore101; i++){//on boucle 20 fois
        identique = false;//false : Chromino identique pas trouvé
        monVecteur = genererCases(2,false,true,false);

        qDebug()<<"Il y a "<<chrominoBicolores101.size()<<" chrominoBicolores et Trouver = "<<!identique;

        while(j<chrominoBicolores101.size() && !identique){
            QVector<Case *> mesCases = chrominoBicolores101[j]->getChromino();
            identique = compareVectorCases(mesCases, monVecteur);

            qDebug()<<"\n"<<i<<" ième chromino--------------------";
            qDebug()<<"\t"<<j<<"ième different : "<<identique;

            if(identique){//true : Si on a trouver un chromino identique dans la list
                //On recommence avec un nouveau vecteur
                j=0;
                identique = false;
                cpt = 0;
                monVecteur = genererCases(2,false,true,false);
            }else{//false : Si le vecteur n'est pas identique à un chromino de la list
                cpt++;//Le nombre de fois où on a pas trouvé de chromino identique
                j++; //Chromino suivant
            }
        }

        qDebug()<<"CPT = "<<cpt;
        if(cpt==chrominoBicolores101.size()){
            //Le chromino est unique donc on le rajoute dans la liste
            chromino_bicolore_101 = new ChrominoBicolore(monVecteur);
            chrominoBicolores101.push_back(chromino_bicolore_101);
        }
        monVecteur.clear();
    }
}

void Game::genererChrominoCameleon()
{
    QVector<Case *> monVecteur(0);
    Chromino *chromino_bicolore_cameleon;

    int j(0);
    int cpt(0);

    //On génére 3 cases de type110. Exemple : bleu bleu vert et on enregistre
    //le premier chrominoBicolore de type 110
    /*if(i==0){*/
    qDebug()<<"\n 0ième chromino--------------------";
    monVecteur = genererCases(2,false,false,true);
    chromino_bicolore_cameleon = new ChrominoBicolore(monVecteur);
    chrominoCameleons.push_back(chromino_bicolore_cameleon);
    //}*/

    bool identique = false;

    for(int i(1); i<maxChrominoCameleon; i++){//on boucle 20 fois
        identique = false;//false : Chromino identique pas trouvé
        monVecteur = genererCases(2,false,false,true);

        qDebug()<<"Il y a "<<chrominoCameleons.size()<<" chrominoBicolores et Trouver = "<<!identique;

        while(j<chrominoCameleons.size() && !identique){
            QVector<Case *> mesCases = chrominoCameleons[j]->getChromino();
            identique = compareVectorCases(mesCases, monVecteur);

            qDebug()<<"\n"<<i<<" ième chromino--------------------";
            qDebug()<<"\t"<<j<<"ième different : "<<identique;

            if(identique){//true : Si on a trouver un chromino identique dans la list
                //On recommence avec un nouveau vecteur
                j=0;
                identique = false;
                cpt = 0;
                monVecteur = genererCases(2,false,false,true);
            }else{//false : Si le vecteur n'est pas identique à un chromino de la list
                cpt++;//Le nombre de fois où on a pas trouvé de chromino identique
                j++; //Chromino suivant
            }
        }

        qDebug()<<"CPT = "<<cpt;
        if(cpt==chrominoCameleons.size()){
            //Le chromino est unique donc on le rajoute dans la liste
            chromino_bicolore_cameleon = new ChrominoBicolore(monVecteur);
            chrominoCameleons.push_back(chromino_bicolore_cameleon);
        }
        monVecteur.clear();
    }
}

void Game::genererChrominoTricolore()
{
    QVector<Case *> monVecteur(0);
    Chromino *chromino_tricolore;

    int j(0);
    int cpt(0);

    //On génére 3 cases de type110. Exemple : bleu bleu vert et on enregistre
    //le premier chrominoBicolore de type 110
    /*if(i==0){*/
    qDebug()<<"\n 0ième chromino--------------------";
    monVecteur = genererCases(3,false,false,false);
    chromino_tricolore = new ChrominoTricolore(monVecteur);
    chrominoTricolores.push_back(chromino_tricolore);
    //}*/

    bool identique = false;

    for(int i(1); i<maxChrominoTricolore; i++){//on boucle 20 fois
        identique = false;//false : Chromino identique pas trouvé
        monVecteur = genererCases(3,false,false,false);

        qDebug()<<"Il y a "<<chrominoTricolores.size()<<" chrominoBicolores et Trouver = "<<!identique;

        while(j<chrominoTricolores.size() && !identique){
            QVector<Case *> mesCases = chrominoTricolores[j]->getChromino();
            identique = compareVectorCases(mesCases, monVecteur);

            qDebug()<<"\n"<<i<<" ième chromino--------------------";
            qDebug()<<"\t"<<j<<"ième different : "<<identique;

            if(identique){//true : Si on a trouver un chromino identique dans la list
                //On recommence avec un nouveau vecteur
                j=0;
                identique = false;
                cpt = 0;
                monVecteur = genererCases(3,false,false,false);
            }else{//false : Si le vecteur n'est pas identique à un chromino de la list
                cpt++;//Le nombre de fois où on a pas trouvé de chromino identique
                j++; //Chromino suivant
            }
        }

        qDebug()<<"CPT = "<<cpt;
        if(cpt==chrominoTricolores.size()){
            //Le chromino est unique donc on le rajoute dans la liste
            chromino_tricolore = new ChrominoTricolore(monVecteur);
            chrominoTricolores.push_back(chromino_tricolore);
        }
        monVecteur.clear();
    }
}

void Game::distribuerChrominoJoueur(const QVector<Chromino *> &ch)
{

}

void Game::remplirSac(QVector<Chromino *> &pioche)
{

}

void Game::initPlateau()
{

}

void Game::on_btn_left_clicked()
{

}

void Game::on_btn_up_clicked()
{

}

void Game::on_btn_right_clicked()
{

}

void Game::on_btn_down_clicked()
{

}

void Game::on_pushButton_clicked()
{

}



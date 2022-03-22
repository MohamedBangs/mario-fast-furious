#ifndef AFFICHEJOUEUR_H_INCLUDED
#define AFFICHEJOUEUR_H_INCLUDED
#include "WinText.h"
#include "../JeuxCore/Joueur.h"
#include <string>
#include <map>
#include <thread>

/**
 * \struct AfficheJeux AfficheJeux.h "voir classe AfficheJeux"
 * \brief class permettant d'afficher une partie de jeu
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe AfficheJeux contient deux attributs privés
 *   WinText *mWin: un pointeur vers la classe WinText dans src/JeuxText
 *    Joueur *mJoueur: un pointeur vers la classe Joueur dans src/JeuxCore
 *	}
 */

class AfficheJeux{

public:

    /**
	 * \fn AfficheJeux(WinText *win)
	 * \brief Constructeur avec parametre. Ce constructeur crée une instance AfficheJeux, fais pointé mWin à l'objet Wintext passé en parametre
	 * \param WinText *win: pointeurs vers Wintext permettant de manipuler ncurses(bibliothèque extern).
	 */
    AfficheJeux(WinText *win);

    /**
     * \fn ~AfficheJeux()
     * \brief Destructeur de la classe. detruit le pointeur mJoueur.
     */
    ~AfficheJeux();

    /**
     * \fn ~lancePartie()
     * \brief Fonction permettant de lancer une partie du jeux
     * \return le rang du joueur
     */
    int lancePartie();

private:

    WinText *mWin;
    Joueur *mJoueur;

};


#endif // AFFICHEJOUEUR_H_INCLUDED

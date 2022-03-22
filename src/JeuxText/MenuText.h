#ifndef MENUTEXT_H_INCLUDED
#define MENUTEXT_H_INCLUDED

#include "WinText.h"
#include <vector>
#include <string>

/**
 * \struct MenuText MenuText.h "voir classe MenuText"
 * \brief class qui lance le menu du jeu(mode textuel)
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe MenuText contient un attribut privés
 *	WinText* mWin: pointeur vers la classe Wintext
 *	}
 */

class MenuText{

private:
     WinText* mWin;
   /**
	 *\fn void setMQuit(bool quit)
	 * \brief permet d'afficher le menu a l'utilisateur
	 * \param std::vector<std::string> const& menu: le menu a afficher
	 * \param int choix: contient la position(entier) du curseur pour choisir
	 */
     void afficheMenu(std::vector<std::string> const& menu, int choix);

public:

    /**
	 * \fn MenuText()
	 * \brief Constructeur avec paramètre, Ce constructeur crée une instance MenuText. initialise le pointeur mWin a win
	 */
     MenuText(WinText *win);

    /**
	 * \fn enum eAction()
	 * \brief Valeur retourner par la fonction membre lireAction
	 */
	enum eAction
	{
		aucun	= 0,//Aucune action.
		nouveau = 1,//Appuie sur nouvelle partie.
		continu = 2,//Appuie sur continuer.
		aide	= 3,// Afficher l'aide.
		quitter	= 4	//Quitter.
	};

    /**
	 * \fn eAction lireAction(bool continuer = false)
	 * \brief retourne le choix de l'utilisateur a la classe TextJeux
	 * \param continuer: valeur booléenne, indique si on veut continuer ou pas
	 * \return un eAction
	 */
    eAction lireAction(bool continuer = false);

};

#endif // MENUTEXT_H_INCLUDED

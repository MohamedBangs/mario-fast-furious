#ifndef TEXTJEUX_H_INCLUDED
#define TEXTJEUX_H_INCLUDED
#include "MenuText.h"
#include "../JeuxCore/Terrain.h"
#include "WinText.h"
#include "AfficheJeux.h"

/**
 * \struct TextJeux TextJeux.h "voir classe TextJeux"
 * \brief class qui lance le jeu mode textuel
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe TextJeux contient six attributs privés
 *	bool mQuit: valeur boulenne vaut true si on quitte le jeu false si non
 *	MenuText mMenuText: un objet vers la classe MenuText
 *	Terrain *mTerrain: un Pointeur vers la classe Terrain
 *   WinText mWin: un objet vers la classe Wintext
 *  AfficheJeux mAfficheJeux: un objet vers la classe AfficheJeux
 *	std::map<std::string,bool> key: un objet type map(associatif clé-valeur) contenant l'evenement clavier
 *	}
 */

class TextJeux{

private:

	bool mQuit;
	MenuText mMenuText;
	Terrain *mTerrain;
    WinText mWin;
    AfficheJeux mAfficheJeux;
	std::map<std::string,bool> key;

    /**
	 * \fn void nouvellePartie()
	 * \brief demande a AfficheJeux de l'ancer une partie du jeu
	 */
    void nouvellePartie();

    /**
	 * \fn void aide()
	 * \brief affiche l'aide
	 */
    void aide();


public:

    /**
	 * \fn TextJeux()
	 * \brief Constructeur par defaut, Ce constructeur crée une instance TextJeux.initialise mQuit a false, mMenuText et mAfficheJeux
	 */
     TextJeux();

    /**
	 * \fn ~TextJeux()
	 * \brief Destructeur, detruit le pointeur mTerrain
	 */
	~TextJeux();

    /**
	 * \fn ~jouer()
	 * \brief démande à la classe AfficheJeux d'afficher une partie du jeu
	 * \return retourne zéro si tous ces bien passé
	 */
	int jouer();

    /**
	 *\fn bool getMQuit() const
	 * \brief Accesseur de la valeur bouléenne quitter
	 * \return la valeur booléenne quitter
	 */
	bool getMQuit() const ;

    /**
	 *\fn void setMQuit(bool quit)
	 * \brief Mutateur de la valeur bouléenne quitter
	 * \param bool quit: indique si le jeu est terminer(true) ou pas(false)
	 */
	void setMQuit(bool quit);
};

#endif // TEXTJEUX_H_INCLUDED

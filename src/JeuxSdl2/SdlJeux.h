#ifndef SDLJEUX_H_INCLUDED
#define SDLJEUX_H_INCLUDED
#include "../JeuxCore/Joueur.h"
#include "../JeuxCore/Terrain.h"
#include "MenuSdl.h"
#include "AfficheJeuxSdl.h"
#include "SdlJeuxUtil.h"
#include "AfficheScore.h"
#include <SDL2/SDL.h>
#include<map>

/**
 * \struct SdlJeux SdlJeux.h "voir classe SdlJeux"
 * \brief class qui lance le jeu mode Graphique
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe SdlJeux contient onze attributs privés
 *	bool continuer: valeur booléene(vaie si le joueur veut continuer, faux si non)
 *  bool finDeJeux: true marque la fin d'une partie, false si non
 *  Joueur *mJoueur: un pointeur vers le joueur
 *	Terrain *mTerrain: un pointeur vers le terrain
 *	AfficheJeuxSdl *mAfficheJeuxSdl: un pointeur vers la classe AfficheJeuxSdl
 *  AfficheScore *mAfficheScore: un pointeur vers la classe AfficheScore
 *  MenuSdl *mMenuSdl: un pointeur vers la classe MenuSdl
 *	SdlJeuxUtil *mSdlJeuxUtil: un pointeur vers SdlJeuxUtil
 * std::map<std::string,std::string> chainSprteIntel: tableau associatif contenant le nom des autres joueurs(intelligence artificielle)
 *  SDL_Window *window = NULL: pointeur de la fenetre principale du jeu
 *  SDL_Renderer *renderer = NULL: pointeur du rendeur de la fenetre principale
 *	}
 */

class SdlJeux{

public:

    /**
	 * \fn SdlJeux
	 * \brief Constructeur par defaut, initilise les attributs en leur valeurs par defaut
	 */
     SdlJeux();

    /**
	 * \fn ~SdlJeux
	 * \brief Destructeur, fait appel a la fonction libereMemoire() pour liberer les objets instenciés
	 */
	~SdlJeux();

    /**
	 * \fn int jouer()
	 * \brief Lance le jeu, retourne 0 si tous c'est bien passé -1 si non
	 */
	int jouer();

    /**
	 * \fn void libereMemoire()
	 * \brief Libere la memoire
	 */
	void libereMemoire();

    /**
	 * \fn void initJeux()
	 * \brief fait appel à la fonction init(...) de la classe SdlJeuxUtil pour initialiser le jeu
	 */
	void initJeux();


private:

	bool continuer, finDeJeux;
	Joueur *mJoueur;
	Terrain *mTerrain;
	AfficheJeuxSdl *mAfficheJeuxSdl;
    AfficheScore *mAfficheScore;

	MenuSdl *mMenuSdl;
	SdlJeuxUtil *mSdlJeuxUtil;
	std::map<std::string,std::string> chainSprteIntel;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /**
	 * \fn void nouvellePartie()
	 * \brief fait appel à la fonction lancePartie() de SdlAfficheJeux pour lancer une partie
	 */
    void nouvellePartie();

};


#endif // SDLJEUX_H_INCLUDED

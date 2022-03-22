#ifndef AFFICHESCORE_H_INCLUDED
#define AFFICHESCORE_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SdlJeuxUtil.h"

/**
 * \struct AfficheScore AfficheScore.h "voir classe AfficheScore"
 * \brief class qui affiche le score après une partie
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe AfficheScore contient cinq attributs privés
 *     #define maxbttn 9 : le nombre maximal des composant graphique afficher ce nombre est invariable il sert à fixer les Texture et Rect
 *      int nb=9;//le nombre de composant graphique affiché a un instant t sur la fenetre score, cet nombre est variable!!
 *      SDL_Texture *element[maxbttn]: les composants de la fenetre
 *{  element[0]: Partie Terminer
 *   element[1] : Classement
 *   element[2]: prémier joueur arrivé
 *   element[3]: deuxieme joueur arrivé
 *   element[4]: troisieme joueur arrivé
 *   element[5]: Meilleur temps
 *   element[6] : Temps
 *   element[7] : Joueur ayant le meilleur temps
 *   element[8] : retour au menu principal
 * }
 * SDL_Rect rect[maxbttn+1]: rectangle contenant les elements de la fenetre principale(l'ordre d'indice des element est le meme que le rectangle) rect[nb] va servir pour le fond d'ecran
 * SDL_Texture *fond: le fond ecran de la fenetre score
 *	}
 */

class AfficheScore{

public:
        /**
         * \fn MenuSdl()
         * \brief Constructeur par defaut
         */
    AfficheScore();
    /**
    * \fn ~AfficheScore()
    * \brief Destructeur, fait appel a la fonction libereMemoire pour desalouer
    */
    ~AfficheScore();

    /**
         * \fn void afficheScoreApresPartie(SDL_Renderer * renderer, SdlJeuxUtil *sdlJeuxUtil)
         * \brief Affiche le score du jeux après une partie du jeu
         * \param SDL_Renderer * renderer: le rendeur de la fenetre principal
         * \param SdlJeuxUtil *sdlJeuxUtil: pointeur vers la classe SdlJeuxUtil
         */
    void afficheScoreApresPartie(SDL_Renderer * renderer, SdlJeuxUtil *sdlJeuxUtil);
private:
#define maxbttn 9  //le nombre maximal des composant graphique afficher ce nombre est invariable il sert à fixer les Texture et Rect
    int nb=9;//le nombre de composant graphique affiché a un instant t sur la sortie score, cet nombre est variable!!
    SDL_Texture *element[maxbttn],*fond=NULL;
    SDL_Rect rect[maxbttn+1]; /*rect[maxbttn] va servir pour le retour au menu principale*/
        /**
         * \fn void libereMemoire()
         * \brief Désaloue la memoire
         */
    void libereMemoire();
};

#endif // AFFICHESCORE_H_INCLUDED

#ifndef MENUSDL_H_INCLUDED
#define MENUSDL_H_INCLUDED
#include "../JeuxCore/Joueur.h"
#include "../JeuxCore/Terrain.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<string>
#include<sstream>
#include<map>

/**
 * \struct MenuSdl MenuSdl.h "voir classe MenuSdl"
 * \brief class qui lance le menu Graphique
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe MenuSdl contient cinq attributs privés
 *     #define maxbttn 7 : le nombre maximal des composant graphique afficher ce nombre est invariable il sert à fixer les Texture et Rect
 *      int nb=7;//le nombre de composant graphique affiché a un instant t sur le menu, cet nombre est variable!!
 *      SDL_Texture *button[maxbttn]: les buttons de la fenetre
 *{  button[0]: 'Nouvelle partie
 *   button[1] : continuer
 *   button[2]: niveau
 *   button[3]: choix terrain
 *   button[4]: choix joueur
 *   button[5]: aide
 *   button[6] : quitter
 * }
 * SDL_Rect rect[maxbttn+1]: rectangle contenant les elements de la fenetre principale(l'ordre d'indice des buttons est le meme que le rectangle) rect[nb] va servir pour le fond menu et pour le titre
 * SDL_Rect emplacemntTitre: l'emplacement du titre sur la fenetre du menu
 * SDL_Texture *fond: le fond ecran de la fenetre menu
 * SDL_Texture *titre: le titre de la fenetre menu
 *	}
 */

class MenuSdl{

private:

#define maxbttn 7  //le nombre maximal des composant graphique afficher ce nombre est invariable il sert à fixer les Texture et Rect
        int nb=7;//le nombre de composant graphique affiché a un instant t sur le menu, cet nombre est variable!!
        SDL_Texture *button[maxbttn],*fond=NULL, *titre=NULL;
        SDL_Rect rect[maxbttn+1]; /*rect[nb] va servir pour le fond menu et pour le titre*/
        SDL_Rect emplacemntTitre;

        /**
         * \fn void menuPrincipale(std::string str, bool & continuer, SDL_Renderer * renderer)
         * \brief affiche le menu principal
         * \param std::string str: l'indice du composant a dessiner sur le menu
         * \param bool & continuer:  si vrai on affiche le button continuer
         * \param SDL_Renderer * renderer: le rendeur de la fenetre principale
         */
        void menuPrincipale(std::string str, bool & continuer, SDL_Renderer * renderer);

public:

        /**
         * \fn MenuSdl()
         * \brief Constructeur par defaut
         */
       MenuSdl();

         /**
         * \fn ~MenuSdl()
         * \brief Destructeur, fait appel à la fonction libereMemoire
         */
       ~MenuSdl();

       /**
         * \fn void libereMemoire()
         * \brief Désaloue toute les pointeurs créer l'ors de l'instancitation de la classe
         */
       void libereMemoire();


        /**
         * \fn enum eAction()
         * \brief Valeur retourner par la fonction membre afficheMenu
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
         * \fn eAction afficheMenu(SDL_Window *window, SDL_Renderer *renderer, Joueur *joueur, Terrain *terrain, std::map<std::string,std::string> &chainSprteIntel, bool &continuer);
         * \brief affiche le menu principal
         *	bool &continuer: valeur booléene(vaie si le joueur veut continuer, faux si non)
         *  Joueur joueur: un pointeur vers le joueur
         *	Terrain * terrain: un pointeur vers le terrain
         * std::map<std::string,std::string> &chainSprteIntel: tableau associatif contenant le nom des autres joueurs(intelligence artificielle)
         *  SDL_Window *window = NULL: pointeur de la fenetre principale du jeu
         *  SDL_Renderer *renderer = NULL: pointeur du rendeur de la fenetre principale
         * \return un eAction
         */
        eAction afficheMenu(SDL_Window *window, SDL_Renderer *renderer, Joueur *joueur, Terrain *terrain, std::map<std::string,std::string> &chainSprteIntel, bool &continuer);

        /**
         * \fn SDL_Texture *loadImage(const char path[], SDL_Renderer * renderer, SDL_Rect & rect)
         * \brief Charge une image en effectant ses dimension dans SDL_Rect & rect
         * \param const char path[]: chemin vers l'image
         * \param SDL_Renderer *renderer: le rendeur de la fenêtre
         * \param SDL_Rect & rect: la position sur la quelle sera affiché l'image dans la fenetre
         * \return retourne la texture associé à l'image
         */
       SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer, SDL_Rect &rect);

};


#endif // MENUSDL_H_INCLUDED

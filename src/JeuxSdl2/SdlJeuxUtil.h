#ifndef SDLJEUXUTIL_H_INCLUDED
#define SDLJEUXUTIL_H_INCLUDED
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

/**
 * \struct SdlJeuxUtil SdlJeuxUtil.h "voir classe SdlJeuxUtil"
 * \brief class metier du module SDL
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 */

class SdlJeuxUtil{

public:

    /**
     * \fn SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
     * \brief Charge une image
     * \param const char path[]: chemin vers l'image
     * \param SDL_Renderer *renderer: le rendeur de la fenêtre
     * \return retourne la texture associé à l'image
     */
    SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer);

    /**
     * \fn SDL_Texture *loadImage(const char path[], SDL_Renderer * renderer, SDL_Rect & rect)
     * \brief Charge une image en effectant ses dimension dans SDL_Rect & rect
     * \param const char path[]: chemin vers l'image
     * \param SDL_Renderer *renderer: le rendeur de la fenêtre
     * \param SDL_Rect & rect: la position sur la quelle sera affiché l'image dans la fenetre
     * \return retourne la texture associé à l'image
     */
    SDL_Texture *loadImage(const char path[], SDL_Renderer * renderer, SDL_Rect & rect);

    /**
     * \fn int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h)
     * \brief initialise la fenetre du jeu
     * \param SDL_Window **window: la fenetre dans la quelle tous les composant sont affichée
     * \param SDL_Renderer **renderer: le rendeur de la fenêtre
     * \param int w: l'argeur de la fenetre
     * \param int h: hauteur de la fenetre
     * \return retourne zéro tous c'est bien passé -1 si non
     */
    int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h);

    /**
     * \fn int initLibrary()
     * \brief initialise la librairy du son(SDL_mixer) et texte(SDL_ttf)
     * \param SDL_Window **window: la fenetre dans la quelle tous les composant sont affichée
     * \param SDL_Renderer **renderer: le rendeur de la fenêtre
     * \param int w: l'argeur de la fenetre
     * \param int h: hauteur de la fenetre
     * \return retourne zéro tous c'est bien passé -1 si non
     */
    int initLibrary();

    /**
     * \fn Uint32 obtenirPixel(SDL_Surface *surface, int x, int y)
     * \brief récupere le pixel d'une image
     * \param SDL_Surface *surface: la surface contenant l'image
     * \param int x: position(x) du pixel à récuperer dans l'image
     * \param int y: position(y) du pixel à récuperer dans l'image
     * \return retourne un entier codé sur 32 bits
     */
    Uint32 obtenirPixel(SDL_Surface *surface, int x, int y);

    /**
     * \fn enum dataScreen
     * \brief contient les information sur la fenetre principale
     *{
     * screenW = 450: largeur de l'ecran
     * screenH = 200: hauteur de l'ecran
     * pxs = 2: valeur ajoutée a la hauteur et largeur de l'ecran
     * pxj=400: decalage entre les positons des joueurs
     * spriteW=80: largeur de mario
     * spriteH=80: hauteur de mario
     * vitesseMinimaleJeux=20: vitesse minimale du joueur
     *}
     */
    enum dataScreen{

         screenW = 450,
         screenH = 200,
         pxs = 2,
         pxj=400,
         spriteW=80,
         spriteH=80,
         vitesseMinimaleJeux=20,
    };


};

#endif // SDLJEUXUTIL_H_INCLUDED

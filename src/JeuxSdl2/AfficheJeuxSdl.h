#ifndef AFFICHEJEUXSDL_H_INCLUDED
#define AFFICHEJEUXSDL_H_INCLUDED
#include "../JeuxCore/Camera.h"
#include "../JeuxCore/Joueur.h"
#include "../JeuxCore/Terrain.h"
#include "../JeuxCore/Collision.h"
#include "SdlJeuxUtil.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include<string>

/**
 * \struct AfficheJeuxSdl AfficheJeuxSdl.h "voir classe AfficheJeuxSdl"
 * \brief class qui lance une partie du jeux
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *  { 	bool quitter: variable bouléenne vaut true si on veut quitter le jeu, false si non
 *	int buffer[SdlJeuxUtil::screenH][SdlJeuxUtil::screenW]: tableau d'entier contenant la protion du terrain a afficher
 *	T_Temps temps: gere le temps dans le jeu(voir plus bas)
 *	Camera *mCamera: Ponteur vers la classe Camera
 *	Joueur *mJoueur: Ponteur vers la classe Joueur
 * 	Terrain *mTerrain: Ponteur vers la classe Terrain
 *	Collision *mCollision: Ponteur vers la classe Collision
 *	SdlJeuxUtil *mSdlJeuxUtil: Ponteur vers la classe SdlJeuxUtil
 *  SDL_Window *window = NULL: pointeur de la fenetre principale du jeu
 *  SDL_Renderer *renderer = NULL: pointeur du rendeur de la fenetre principale
 *  SDL_Texture *sprite: sprite(image) du joueur physique
 *  SDL_Texture *sprite2 : sprite du deuxieme joueur
 *  SDL_Texture *sprite3: sprite du troisieme joueur
 *  SDL_Texture *piste: la piste(Terrain)
 *  SDL_Surface *pisteLogique: la piste logique pour la gestion de la collision(pixel)
 *  SDL_Surface *surfVitesse: position du texte vitesse dans la fenetre
 *  SDL_Surface *surfTemps: position du texte Temps ecoulé dans la fenetre
 *  SDL_Texture *textureVitesse: la texture de la vitesse(contient la vitesse)
 *  SDL_Texture *textureTemps: la texture du temps(contient le temps ecoulé)
 *  SDL_Texture *textureRetourMenu: contient le button retour au menu principal
 *  TTF_Font *police : Création du pointeur qui gère le texte sur la fenetre de jeu
 *  SDL_Color couleurRouge : la couleur du texte sur la fenetre de jeu
 *  char charVitesse[20]  Tableau de char suffisamment grand pour contenir le texte de la vitesse
 *	char charTemps[20] : Tableau de char suffisamment grand pour contenir le texte du temps
 *  Mix_Music *musique: Création du pointeur de type Mix_Music
 *  Mix_Chunk *son: un pointeur pour stocker un .WAV
 *  SDL_Rect vueTerrain: positon du portion de terrain dans la fenetre du jeu
 *  SDL_Rect vueJoueur: position du joueur sur la fenetre du jeu
 *  SDL_Rect vueJoueur2: position du jouer2 sur la fenetre du jeu
 *  SDL_Rect vueJoueur3: position du joueur3 sur la fenetre du jeu
 *  SDL_Rect animateur[3]: animation des joueurs (lorsque la touche UP, LEFT, DOWN, RIGHT sont appuyée)
 *  SDL_Rect rectVitesse: position de la vitesse sur la fe,etre du jeu
 *  SDL_Rect rectTemps : position du temps sur la fenetre du jeu
 *  SDL_Rect rectRetourMenu: position du button retour menu
 *	}
 */
class AfficheJeuxSdl{

public:

  /**
    * \fn  AfficheJeuxSdl(SDL_Window *p_window, SDL_Renderer *p_renderer, Joueur *p_joueur, Terrain * p_terrain, SdlJeuxUtil *p_SdlJeuxUtil);
    * \brief constructeur de la classe
    *  Joueur *p_joueur: un pointeur vers le joueur
    *  Terrain * p_terrain: un pointeur vers le terrain
    *  SdlJeuxUtil * p_SdlJeuxUtil: un pointeur vers SdlJeuUtil
    *  SDL_Window *window = NULL: pointeur de la fenetre principale du jeu
    *  SDL_Renderer *renderer = NULL: pointeur du rendeur de la fenetre principale
    */
    AfficheJeuxSdl(SDL_Window *p_window, SDL_Renderer *p_renderer, Joueur *p_joueur, Terrain * p_terrain,
                                                                             SdlJeuxUtil *p_SdlJeuxUtil);
    /**
    * \fn  AfficheJeuxSdl(SDL_Window *p_window, SDL_Renderer *p_renderer, Joueur *p_joueur, Terrain * p_terrain, SdlJeuxUtil *p_SdlJeuxUtil);
    * \brief Destructeur de la classe, fait appel à libereMemoire
    */
    ~AfficheJeuxSdl();

    /**
    * \fn int lancePartie(bool & continuer, std::string & jouer2, std::string & Joueur3, bool &findDeJeux)
    * \brief lance une partie du jeu
    * \param bool & continuer: vaut true si on continue là on s'etait arreté false si non
    * \param std::string & jouer2: nom du deuxieme joueur
    * \param std::string & jouer3: nom du troisième joueur
    * \param bool &findDeJeux: vaut true après le tours(2*fois) du terrain false si non
    */
    void lancePartie(bool & continuer, std::string & jouer2, std::string & Joueur3, bool &findDeJeux);

    /**
    * \fn void onJoue(bool &findDeJeux)
    * \brief affiche le jeu
    *  bool &findDeJeux: vaut true après le tours(2*fois) du terrain false si non
    */
    void onJoue(bool &findDeJeux);

private:

    /**
    * \fn void renitialiseEtatJeux(std::string jouer2, std::string Joueur3)
    * \brief reinitialise les joueurs et le composants graphique
    * \param std::string & jouer2: nom du deuxieme joueur
    * \param std::string & jouer3: nom du troisième joueur
    */
    void renitialiseEtatJeux(std::string jouer2, std::string Joueur3);

    /**
    * \fn void initJeux()
    * \brief initialise la librairy son et texte et d'autres composants necessaires
    */
    void initJeux();

    /**
    * \fn bool finDuJeux()
    * \brief si le joueur physque a fait deux tour du terrain retourne true pour la fin de la partie , false si non
    * \return retourne true(fin de la partie), false si non
    */
    bool finDuJeux();

    /**
    * \fn void libereMemoire()
    * \brief désaloue la memoire
    */
    void libereMemoire();

    /**
    * \fn void etatMusique()
    * \brief l'etat de la musique (pause ou play)
    */
    void etatMusique();

    /**
     * \struct Structure T_Temps
     * \brief gère le temps de pause du jeu et le temps ecoulé depuis le debut d'une partie
     *{
     * unsigned int difference: temps l'orsqu'on part en pause
     * unsigned int tempsActuel: temps ecouler
     *}
     */
    typedef struct T_Temps  //Sert à régler les timers
    {
        unsigned int difference;    //Lors des pauses, celui se voit modifié
        unsigned int tempsActuel;   //L'étalon "temps" utilisé par mes timers
    }T_Temps;
	bool quitter;
	int buffer[SdlJeuxUtil::screenH][SdlJeuxUtil::screenW];
	T_Temps temps;

	Camera *mCamera;
	Joueur *mJoueur;
	Terrain *mTerrain;
	Collision *mCollision;
	SdlJeuxUtil *mSdlJeuxUtil;

    SDL_Window *window=NULL;
    SDL_Renderer *renderer=NULL;

    SDL_Texture *sprite=NULL, *sprite2=NULL, *sprite3=NULL, *piste=NULL;

    SDL_Surface *pisteLogique=NULL, *tmpPl=NULL;

    SDL_Surface *surfVitesse = NULL, *surfTemps=NULL;

    SDL_Texture *textureVitesse=NULL, *textureTemps=NULL, *textureRetourMenu=NULL;

    TTF_Font *police = NULL;

    SDL_Color couleurRouge = {255, 0, 0};

    char charVitesse[20] = ""; /* Tableau de char suffisamment grand pour vitesse */
	char charTemps[20] = ""; /* Tableau de char suffisamment grand pour vitesse */

	//musique et son
     Mix_Music *musique; //Création du pointeur de type Mix_Music
     Mix_Chunk *son;//Créer un pointeur pour stocker un .WAV

    SDL_Rect vueTerrain={0, SdlJeuxUtil::screenH * SdlJeuxUtil::pxs,
                        SdlJeuxUtil::screenW * SdlJeuxUtil::pxs,
                        SdlJeuxUtil::screenH * SdlJeuxUtil::pxs};

    SDL_Rect vueJoueur={vueTerrain.x + SdlJeuxUtil::pxj,
                        SdlJeuxUtil::screenH + SdlJeuxUtil::pxj,
                        SdlJeuxUtil::spriteW, SdlJeuxUtil::spriteH};

    SDL_Rect vueJoueur2={vueTerrain.x + SdlJeuxUtil::pxj - 300,
                        SdlJeuxUtil::SdlJeuxUtil::screenH + SdlJeuxUtil::pxj - 50,
                        SdlJeuxUtil::spriteW, SdlJeuxUtil::spriteH};

    SDL_Rect vueJoueur3={vueTerrain.x + SdlJeuxUtil::pxj - 150,
                        SdlJeuxUtil::screenH + SdlJeuxUtil::pxj,
                        SdlJeuxUtil::spriteW, SdlJeuxUtil::spriteH};
    SDL_Rect animateur[3];
    SDL_Rect rectVitesse, rectTemps, rectRetourMenu;

};

#endif // AFFICHEJEUXSDL_H_INCLUDED

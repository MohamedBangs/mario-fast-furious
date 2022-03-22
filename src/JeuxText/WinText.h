#ifndef WINTEXT_H_INCLUDED
#define WINTEXT_H_INCLUDED

#include <ncurses.h>

/**
 * \struct WinText WinText.h "voir classe WinText"
 * \brief class qui gère la bibliothèque ncurses
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe WinText contient huit attributs privés
 *  WINDOW *boiteJoeur: un objet WINDOW de ncurses, répresente le joueur physique sur le terrain
 *  WINDOW *masqueJoeur: un objet WINDOW de ncurses, permet de masquer le joueur a la position précédente
 *  WINDOW *intelArtificiel[2]: un tableau d'objet WINDOW de ncurses, répresente les deux joeurs autres joeurs(intelligence artificiel)
 *  pos position[3]: la position de masquage( 0 pour masqueJoeur ,1 pour inteligence[0] et 2 pour inteligence[1])
 *	}
 */

class WinText{

 public:

    /**
	 * \fn WinText()
	 * \brief Constructeur par defaut, initialise la biblithèque ncurses
	 */
	WinText();

    /**
	 * \fn ~WinText()
	 * \brief Destructeur, detruit les WINDOWS et appel le destructeur de ncurses
	 */
    ~WinText();

    /**
	 * \fn void effacer()
	 * \brief efface la fenetre
	 */
	void effacer();
    /**
	 * \fn void dessiner(int px, int py, char carac)
	 * \brief dessiner un caractère(carac) à la position px et py
	 * \param int px: position du caractère par rapport à l'axe x
	 * \param int py: position du caractère par rapport à l'axe y
     * \param char carac: le caractère à affichier
	 */
	void dessiner(int px, int py, char carac);

    /**
	 * \fn void dessinerTxt(int px, int py, char const* txt)
	 * \brief dessiner du texte à la position px et py
	 * \param int px: position du caractère par rapport a l'axe x
	 * \param int py: position du caractère par rapport a l'axe y
     * \param char const* txt: le texte a affichier
	 */
	void dessinerTxt(int px, int py, char const* txt);

    /**
	 * \fn void dessinerTxtCentre(int py, char const* txt)
	 * \brief dessiner du texte au centre de la fenetre
	 * \param int py: position du caractère par rapport a l'axe y
     * \param char const* txt: le texte a affichier
	 */
	void dessinerTxtCentre(int py, char const* txt);

    /**
	 * \fn void afficher()
	 * \brief rafraichit la fenetre
	 */
	void afficher();

   /**
	 * \fn void update(int px,int py)
	 * \brief dessine le joueur, l'intelligences artificielles et le terrain au bon endroid
	 * \param int px: position du joueur sur l'axe x
	 * \param int py: position du joueur sur l'axe y
	 */
	void update(int px,int py);

    /**
	 * \fn int getNbLigneScreen()
	 * \brief accesseur du nombre de ligne de l'ecran
	 * \return retourne le nombre de ligne de l'ecran
	 */
    int getNbLigneScreen();

    /**
	 * \fn int getNbColsScreen()
	 * \brief accesseur du nombre de colonne de l'ecran
	 * \return retourne le nombre de colonne de l'ecran
	 */
    int getNbColsScreen();

    /**
	 * \fn int getLimitDroit()
	 * \brief accesseur de la limite Droite de la piste
	 * \return retourne la limite droite de la piste
	 */
    int getLimitDroit();

    /**
	 * \fn int getLimitGauche()
	 * \brief accesseur de la limite Gauche de la piste
	 * \return retourne la limite gauche de la piste
	 */
    int getLimitGauche();

    /**
	 * \fn void update(int px,int py)
	 * \brief initialise le jeu, positionne le joueur physique à la position px,py
	 * \param int px: position du joueur sur l'axe x
	 * \param int py: position du joueur sur l'axe y
	 */
    void init(int px, int py);

 private:

    /**
     * \struct struture pos(position du joueur)
     * \brief contient la positon x et y du joueur
	 */
    struct pos{
        int x=0;
        int y=0;
    };

    WINDOW *boiteJoeur;
    WINDOW *masqueJoeur;
    WINDOW *intelArtificiel[2];
    pos position[3];/* 0 pour masque,1 pour inteligence1 2 pour l'autre*/

    /**
	 * \fn void bougeIntelgenceArtificiel()
	 * \brief permet de bouger l'intelligence artificielle
	 */
    void bougeIntelgenceArtificiel();

    /**
	 * \fn void initPlayeur(int x,int y)
	 * \brief initialise le joueur a la position (x,y)
     * \param int x: position du joueur sur l'axe x
	 * \param int y: position du joueur sur l'axe y
	 */
    void initPlayeur(int x,int y);

    /**
	 * \fn void initTerrain()
	 * \brief initialise le terrain avec les valeur par defaut
	 */
    void initTerrain();

};

#endif // WINTEXT_H_INCLUDED

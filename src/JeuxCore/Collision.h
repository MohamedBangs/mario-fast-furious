#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include "Terrain.h"
#include "Joueur.h"

/**
 * \struct Collision Collision.h "voir classe Collision"
 * \brief class qui gère la collision du joueur physique et l'intelligence artificielle.
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe Collision contient deux attributs privés
     int bordurePisteDroite: valeur entière, contient la limite de la piste a droite
     int bordurePisteGauche: valeur entière, contient la limite de la piste a gauche;
	}
 */

class Collision{

private:
    int bordurePisteDroite;
    int bordurePisteGauche;

public:

    /**
     * \fn Collision();
     * \brief Constructeur par défaut. Ce constructeur crée une nouvelle instance de la classe Collision.
     *Initialise les attributs(bordurePisteDroite, bordurePisteGauche) en fonction du de la piste.
     */
    Collision();

    /**
	 * \fn bool collisionJoueurJoueur(int x1, int x2, int y1, int y2)
	 * \brief gere la collision entre deux joueurs.
	 * \param x1 position du joueur 1 par rapport a l'axe x.
	 * \param x2 position du joueur 2 par rapport a l'axe x.
	 * \param y1 position du joueur 1 par rapport a l'axe 1.
	 * \param y2 position du joueur 2 par rapport a l'axe y.
     * \return true si y'a eu collision et false si non
	 */
    bool collisionJoueurJoueur(int x1, int x2, int y1, int y2);

    /**
	 * \fn bool collisionJoueurTerrainDroite(int x)
	 * \brief gere la collision entre un joueur et le coté droit du terrain.
	 * \param x position du joueur par rapport a l'axe x.
     * \return true si y'a eu collision et false si non
	 */
    bool collisionJoueurTerrainDroite(int x);

    /**
	 * \fn bool collisionJoueurTerrainGauche(int x)
	 * \brief gere la collision entre un joueur et le coté gauche du terrain.
	 * \param x position du joueur par rapport a l'axe x.
     * \return true si y'a eu collision et false si non
	 */
    bool collisionJoueurTerrainGauche(int x);

    /**
	 * \fn void setBordurePisteDroiteGauche(int g, int d)
	 * \brief muttateur de la valeur de la bordure gauche et droite du terrain choisi dans le menu
	 * \param g valeur entière de la bordure gauche
	 * \param d valeur entière de la bordure droite.
	 */
    void setBordurePisteDroiteGauche(int g, int d);

    /**
	 *\fn int getBordurePisteDroite() const
	 * \brief Accesseur de la valeur de la bordure droite
	 * \return la valeur de la bordure droite
	 */
    int getBordurePisteDroite() const;

    /**
	 *\fn int getBordurePisteGauche() const
	 * \brief Accesseur de la valeur de la bordure gauche
	 * \return la valeur de la bordure gauche
	 */
    int getBordurePisteGauche()const;

};

#endif // COLLISION_H_INCLUDED

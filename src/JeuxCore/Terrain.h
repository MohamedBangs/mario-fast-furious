#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include<string>

/**
 * \struct Terrain Terrain.h "voir classe Terrain"
 * \brief gère le terrain choisi dans le menu
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe Terrain contient trois attributs privés
      infosTerrainChoisi infos: structure contenant les informations du terrrain choisi
      int dimensionX,dimensionY: les dimensions (x,y) du terrain
      std::string nom: le nom du terrain, ce nom permet de charger le terrain
	}
 */

class Terrain{

public:

   /**
     * \fn Terrain();
     * \brief Constructeur par défaut. Ce constructeur crée une nouvelle instance de la classe Terrain.
     *Initialise les attributs(dimensionX, dimensionX) en des valeurs par defauts.
    */
    Terrain();

    /**
	 * \fn Terrain(int dimx,int dimy)
	 * \brief Constructeur avec parametre. Ce constructeur crée le terrain avec dimension(dimx,dimy).
	 * \param dimx dimension horizontale du terrain.
	 * \param dimx dimension verticale du terrain.
	 */
    Terrain(int dimx,int dimy);

    /**
	 *\fn int getDimensionX() const
	 * \brief Accesseur de la dimension horizontale du terrain
	 * \return la dimension horizontale du terrain
	 */
    int getDimensionX() const;

    /**
	 *\fn void setDimensionX (int x)
	 * \brief Muttateur de la dimension horizontale du terrain
	 * \param x la nouvelle dimension horizontale du terrain.
	 */
    void setDimensionX (int x);

    /**
	 *\fn int getDimensionY () const
	 * \brief Accesseur de la dimension verticale du terrain
	 * \return la valeur de la dimension verticale du terrain
	 */
    int getDimensionY () const;

    /**
	 *\fn void setDimensionY (int y)
	 * \brief Muttateur de la dimension verticale du terrain
	 * \return la nouvelle dimension verticale du terrain
	 */
    void setDimensionY (int y);

    /**
	 *\fn std::string getNom()const
	 * \brief Accesseur du nom de terrain
	 * \return le nom du terrain
	 */
    std::string getNom()const;

    /**
	 *\fn void setNom(std::string nm)
	 * \brief Muttateur du nom de terrain
	 * \param std::string nm: le nouveau nom du terrain
	 */
    void setNom(std::string nm);
    /**
	 *\fn int getTempsRequis() const
	 * \brief Le temps minimal pour effectuer le tour d'un terrain
	 * \return valeur entière(le temps minimal)
	 */
    int getTempsRequis() const;

    /**
	 *\fn void setTempsRequis(int tr)
	 * \brief Muttateur du tempsRequis pour finir le tour d'un terrain
	 * \param int tr: le nouveau temps requis
	 */
    void setTempsRequis(int tr);

    /**
	 *\fn float getBandeFinaleXmin() const
	 * \brief l'abscisse minimal du point d'arrivé pour terminer le jeu
	 * \return valeur réel(l'abscisse minimal)
	 */
    float getBandeFinaleXmin() const;

    /**
	 *\fn void setBandeFinaleXmin(float xmin)
	 * \brief Muttateur de l'abscisse minimal du point d'arrivé pour terminer le jeu
	 * \param float xmin: la nouvelle abscisse minimale du point d'arrivé
	 */
    void setBandeFinaleXmin(float xmin);

    /**
	 *\fn float getBandeFinaleXmax() const
	 * \brief l'abscisse maximal du point d'arrivé pour terminer le jeu
	 * \return valeur réel(l'abscisse maximale)
	 */
    float getBandeFinaleXmax() const;

    /**
	 *\fn void setBandeFinaleXmax(float xmax)
	 * \brief Muttateur de l'abscisse maximal du point d'arrivé pour terminer le jeu
	 * \param float xmax: la nouvelle abscisse maximale du point d'arrivé
	 */
    void setBandeFinaleXmax(float xmax);

    /**
	 *\fn float getBandeFinaleYmin() const
	 * \brief l'ordonnée minimal du point d'arrivé pour terminer le jeu
	 * \return valeur réel(l'ordonnée minimale)
	 */
    float getBandeFinaleYmin()const;

    /**
	 *\fn void setBandeFinaleYmin(float ymin)
	 * \brief Muttateur de l'ordonnée minimal du point d'arrivé pour terminer le jeu
	 * \param float ymin: le nouveau ordonnée minimal du point d'arrivé
	 */
    void setBandeFinaleYmin(float ymin);

    /**
	 *\fn float getBandeFinaleYmax() const
	 * \brief l'ordonnée maximal du point d'arrivé pour terminer le jeu
	 * \return valeur réel(l'ordonnée maximal)
	 */
    float getBandeFinaleYmax()const;

    /**
	 *\fn void setBandeFinaleYmax(float ymax)
	 * \brief Muttateur de l'ordonnée maximal du point d'arrivé pour terminer le jeu
	 * \param float ymax: le nouveau ordonnée maximal du point d'arrivé
	 */
    void setBandeFinaleYmax(float ymax);


private:

    /**
     * \struct structure infosTerrainChoisi
     * \brief contient :{
     * NB: tous ces attributs change en fonction du terrain
     * int tempsRequis: temps requis(minimum) pour faire un tour du terrain
     * float bandeFinaleXmin: l'absicisse minimale du point d'arrivé
     * float bandeFinaleXmax: l'absicisse maximal du point d'arrivé
     * float bandeFinaleYmin: l'ordonnée minimal du point d'arrivé
     * float bandeFinaleYmax: l'ordonnée maximum du point d'arrivé
     * }
     */
    typedef struct infosTerrainChoisi
    {
        int tempsRequis=0;
        float bandeFinaleXmin=0, bandeFinaleXmax=0;
        float bandeFinaleYmin=0, bandeFinaleYmax=0;
    }infosTerrainChoisi;

    infosTerrainChoisi infos;
    int dimensionX,dimensionY;
    std::string nom;

};


#endif // TERRAIN_H_INCLUDED

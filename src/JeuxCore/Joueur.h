#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include<string>
#include<map>

/**
 * \struct Joueur Joueur.h "voir classe Joueur"
 * \brief class permettant de gerer le joueur physique et l'intelligence artificielle.
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe Joueur contient cinq attributs privés
    std::string nom: le nom du joueur
	Point position: la position(x,y,moveRight,left) du joueur
	float deceleration: la décélération du joueur, plus la décélération augmente la vitesse du joueur diminue et inversement
	bool jeJoue: vaut true si le joueur bouge et false si non
	int nombreToure: le nombre de tour effectué par le joueur
	}
 */

class Joueur{

private:


    /**
     * \struct structure Point
     * \brief contient la position(x,y) et le déplacement du joueur à gauche et droite
     * {
     * moveRight: le nombre de fois le joueur a tourner vers la droite avant d'appuyer la touche gauche
     * moveLeft: le nombre de fois le joueur a tourner vers la gauche avant d'appuyer la touche droite
     * }
     */
    struct Point {
        float x, y;
        int moveRight,moveLeft;
    };

    std::string nom;
	Point position;
	float deceleration;
	bool jeJoue;
	int nombreTour;

public:
     /**
     * \fn Joueur();
     * \brief Constructeur par défaut. Ce constructeur crée une nouvelle instance de la classe Joueur.
     *Initialise les attributs(position, deceleration, jeJoue et nombreToure.
     */
    Joueur();

    /**
	 * \fn Joueur(float px, float py)
	 * \brief Constructeur avec parametre. Ce constructeur crée un nouveau joueur avec position(px,py).
	 * \param px position du joueur par rapport à l'axe x.
	 * \param py position du joueur par rapport à l'axe y.
	 */
    Joueur(float px, float py);

	/**
	 *\fn float getPositionX() const
	 * \brief Accesseur de la valeur position.x du joueur
	 * \return la valeur position du joueur par rapport à l'axe x
	 */
	float getPositionX() const;

    /**
	 *\fn float getPositionY() const
	 * \brief Accesseur de la valeur position.y du joueur
	 * \return la valeur position du joueur par rapport à l'axe y
	 */
	float getPositionY() const;

    /**
	 * \fn void setPositionXY(const float x, const float y);
	 * \brief Muttateur de position. Change la position(x,y) du joueur en (x, y) passé en parametre
	 * \param x valeur réel pour la position en x
	 * \param y valeur réel pour la position en y
	 */
	void setPositionXY(const float x,const float y);

    /**
	 * \fn void setMoveLeftRight(const float x, const float y);
	 * \brief nombre de fois dont le joueur s'est tourné a gauche et droite
	 * \param left valeur entière: le nombre de fois le joueur c'est tourner a gauche avant de cliquer la touche droite
	 * \param right valeur entière: le nombre de fois le joueur c'est tourner a droite avant de cliquer la touche gauche
	 */
	void setMoveLeftRight(const int left,const int right);

    /**
	 *\fn int getMoveRight()const
	 * \brief Accesseur de la valeur position.moveRight du joueur
	 * \return la valeur position.moveRight
	 */
	int getMoveRight()const;

    /**
	 *\fn int getMoveLeft()const
	 * \brief Accesseur de la valeur position.moveLeft du joueur
	 * \return la valeur position.moveLeft
	 */
    int getMoveLeft()const ;

    /**
	 * \fn void setNom(const std::string n)
	 * \brief muttateur pour le nom du joueur
	 * \param n chaine de caractere: contient le nom du joueur
     */
	void setNom(const std::string n);

    /**
	 *\fn std::string getNom() const
	 * \brief Accesseur du nom de joueur
	 * \return la chaine de caractère nom
	 */
	std::string getNom() const;

    /**
	 *\fn float getDeceleration() const
	 * \brief Accesseur de la décélération du joueur, plus cette décélération est petite, la vitesse s'augmente,
	 * la vitesse diminue quant la décélération s'augmente
	 * \return un réel contenant la valeur de la décélération
	 */
	float getDeceleration() const;

    /**
	 *\fn void setDeceleration(const float decel)
	 * \brief muttateur de la décélération du joueur
	 * \param decel entier: contient la valeur à ajouter à la décélération
	 */
	void setDeceleration(const float decel);

    /**
	 *\fn bool getJeJoue() const
	 * \brief accesseur de l'attribut jeJoue, indiquant si le joueur bouge ou pas
	 */
	bool getJeJoue() const;

    /**
	 *\fn float getNombreTour() const
	 * \brief accesseur du nombre de tour du joueur, indiquant le nombre de tour effectué par le joueur
	 */
	float getNombreTour() const;

    /**
	 *\fn float setNombreTour(int nb)
	 * \brief muttateur du nombre de tour
	 * \param nb entier: contient la valeur à ajouter au nombre de tour
	 */
	float setNombreTour(int nb);
};


#endif // VOITURE_H_INCLUDED

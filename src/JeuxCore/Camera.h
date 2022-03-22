#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include "Joueur.h"
#include<math.h>

/**
 * \struct Camera Camera.h "voir classe Camera"
 * \brief class permettant de gerer la camera dans le jeux.
 * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
 * \version 2.0
 * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
 *
 *  { la classe Camera contient sept attributs privés
    Point position: donne la postion de la caméra
    float direction: indique la direction(gauche droit) de la caméra
	float znear: position de la caméra par rapport à l'axe Z( interpollation vue proche)
	float zfar: position de la caméra par rapport à l'axe Z( interpollation vue lointaine)
	Line near: face avant de la caméra
	Line far: face avant de la caméra
	float horizon: la hauteur de la caméra par rapport au sol
	}
 */

class Camera{

private:

    struct Point {
        float x, y;
    };

public:
     /**
     * \fn Camera();
     * \brief Constructeur par défaut. Ce constructeur crée une nouvelle instance de la classe Camera. Initialise les attributs.
     */
    Camera();

    /**
	 * \fn void re_init()
	 * \brief Fonction permettant de reinitialise les attributs de la classe Camera pour chaque nouvelle partie.
	 */
    void re_init();

    /**
     * \struct Line
     * \brief structure permettant de gerer .
     * \author Bangoura Mohamed, Diallo Mamadou Lamarana et Tomassi Enzo
     * \version 1.0
     * \date debut 04 Fevrier 2020, fin 20 fevrier 2020
     *
     *  { la classe Camera contient sept attributs privés
    Point position: donne la postion de la caméra
    float direction: indique la direction(gauche droit) de la caméra
	float znear: position de la caméra par rapport à l'axe Z( interpollation vue proche)
	float zfar: position de la caméra par rapport à l'axe Z( interpollation vue lointaine)
	Line near: face avant de la caméra
	Line far: face avant de la caméra
	float horizon: la hauteur de la caméra par rapport au sol
	}
 */
    struct Line {
        Point a, b;
        float getDist() {
            float x = a.x - b.x;
            float y = a.y - b.y;
            return sqrt(x*x + y*y);
        }
    };

    struct IPoint {
	int x, y;
    };

    float getPositionX() const ;
    void setPositionX(float px);

    float getPositionY() const;
    void setPositionY(float py);

    float getHorizon() const;
    void setHorizon(float hori);

    float getDirection() const;
    void setDirection(float direc);
    Line getProjected(float v);
    IPoint getTexCoords(float u, Line& line,int larg, int haut);

	void update();


private:

    struct ILine {
        IPoint a, b;
    };
    Point position;
    float direction;
	float znear;
	float zfar;
	Line near;
	Line far;
	float horizon;
	Point transformPoint(Point& p);
};


#endif // CAMERA_H_INCLUDED

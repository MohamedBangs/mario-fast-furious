#include "Joueur.h"
#include <iostream>
#include <cmath>

Joueur::Joueur(float px, float py){

    this->position.x=px;
    this->position.y=py;
    this->jeJoue=false;
    this->deceleration=0;
    this->nombreTour=0;
}
Joueur::Joueur(){
    this->nom="data/images/mario1.png";//joueur par default
}

void Joueur::setDeceleration(float decel) {

    if(this->deceleration < -11){
        if(decel>0){//on veut decelerer
          this->deceleration+=decel;
        }
       // this->deceleration=-15;//vitesse maximal d'un joueur;
        this->jeJoue=true;
    }
    else if(this->deceleration>5){
         if(decel<0){ //on veut accelerer
            this->deceleration+=decel;
         }
        this->jeJoue=false;
    }else{
         this->deceleration+=decel;
         this->jeJoue=true;
    }

}
float Joueur::getPositionX() const { return position.x; }
float Joueur::getPositionY() const { return position.y; }

void Joueur::setPositionXY(const float x,const float y) {
    position.x = x;
    position.y=y;
}

void Joueur::setMoveLeftRight(const int left,const int right) {
    position.moveLeft += left;
    position.moveRight += right;
}
int Joueur::getMoveRight()const { return this->position.moveRight; }
int Joueur::getMoveLeft()const { return this->position.moveLeft; }

void Joueur::setNom(const std::string n){ nom=n; }
std::string Joueur::getNom() const { return nom; }

float Joueur::getDeceleration() const { return deceleration; }

bool Joueur::getJeJoue() const { return jeJoue; }

float Joueur::getNombreTour() const { return nombreTour; }
float Joueur::setNombreTour(int nb) { nombreTour= nombreTour+nb; }

#include "Collision.h"

Collision::Collision(){
    this->bordurePisteDroite=20;
    this->bordurePisteGauche=20;
}

bool Collision::collisionJoueurTerrainDroite(int x){

    return x >= this->bordurePisteDroite;
}
bool Collision::collisionJoueurTerrainGauche(int x){

    return x >= this->bordurePisteGauche;
}

void Collision::setBordurePisteDroiteGauche( int d , int g){
    this->bordurePisteDroite=d;
    this->bordurePisteGauche=g;
}

int Collision::getBordurePisteDroite() const{
    return this->bordurePisteDroite;
}

int Collision::getBordurePisteGauche()const{
    return this->bordurePisteGauche;
}

#include "SdlJeux.h"
#include <iostream>
#include<cmath>

SdlJeux::SdlJeux(){

    this->mMenuSdl=new MenuSdl();
    this->chainSprteIntel["Joeur2"]="data/images/mario2.png";//par defaut
    this->chainSprteIntel["Joeur3"]="data/images/mario3.png";//par defaut
    this->continuer=false;
    this->finDeJeux=false;
    this->mJoueur=new Joueur();
    this->mTerrain=new Terrain();
    this->mAfficheScore=new AfficheScore();
}

SdlJeux::~SdlJeux(){
    this->libereMemoire();
}

void SdlJeux::initJeux(){

     if( 0 != this->mSdlJeuxUtil->init(&this->window,&this->renderer,SdlJeuxUtil::screenW * SdlJeuxUtil::pxs,
                                 SdlJeuxUtil::pxs * SdlJeuxUtil::screenH * SdlJeuxUtil::pxs) ){
            this->libereMemoire();
      }
    this->mAfficheJeuxSdl=new AfficheJeuxSdl(this->window, this->renderer, this->mJoueur, this->mTerrain, this->mSdlJeuxUtil);
}

int SdlJeux::jouer(){

    this->initJeux();
    MenuSdl::eAction action = MenuSdl::aucun;
    while (action != MenuSdl::quitter)
    {
        action = this->mMenuSdl->afficheMenu(this->window, this->renderer, this->mJoueur, this->mTerrain,
                                             this->chainSprteIntel, this->continuer);
        switch (action)
        {
            //	Lancer une nouvelle partie
            case MenuSdl::nouveau:
            {
                this->continuer=false;
                this->mJoueur->setNombreTour(1);//le premier tours du joueur
                this->nouvellePartie();
                if(this->finDeJeux){
                    std::cout<<"fin de jeux"<<std::endl;
                    this->continuer=false;
                    this->mAfficheScore->afficheScoreApresPartie(this->renderer, this->mSdlJeuxUtil);
                }
            }
            break;

            //	Continuer une partie
            case MenuSdl::continu:
            {
              this->continuer=true;
              this->nouvellePartie();
            }
            break;

            //	quitter!!
            case MenuSdl::quitter:
            {
                 this->libereMemoire();
            }
            break;

            default:
            {	}

        }
    }
   return 0;
}

void SdlJeux::nouvellePartie(){

    this->mJoueur->setMoveLeftRight(0,0);
    this->mAfficheJeuxSdl->lancePartie(this->continuer, this->chainSprteIntel["Joeur2"], this->chainSprteIntel["Joeur3"], this->finDeJeux);
}

void SdlJeux::libereMemoire(){
     delete this->mMenuSdl;
     delete this->mJoueur;
     delete this->mTerrain;
     delete this->mAfficheJeuxSdl;
     delete this->mAfficheScore;
     if(NULL != this->renderer)
        SDL_DestroyRenderer(this->renderer);
     if(NULL != this->window)
        SDL_DestroyWindow(this->window);
    SDL_Quit();
}


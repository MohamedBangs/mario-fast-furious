#include "AfficheJeux.h"

AfficheJeux::AfficheJeux(WinText *win) : mWin(win){

    int x=(this->mWin->getNbLigneScreen() / 2)+(this->mWin->getNbLigneScreen() / 3);
	int y=this->mWin->getNbColsScreen() /2;
	this->mJoueur = new Joueur(x,y);
}

AfficheJeux::~AfficheJeux(){
    delete this->mJoueur;
}

int AfficheJeux::lancePartie(){

    bool quitter=false;
    this->mWin->effacer();
    this->mWin->init(this->mJoueur->getPositionX(),this->mJoueur->getPositionY());
    int x=(LINES / 2)+(LINES / 3), y=COLS/2;
    while(!quitter){
     int clavier = getch();
			switch (clavier)
			{
				case KEY_UP:
				      if(x-1==0) { x++; quitter=true; return 1;}
                      else x--;
				break;
				case KEY_DOWN:
					  if(x+3==this->mWin->getNbLigneScreen()) x--;
					  else x++;
				break;
				case KEY_LEFT:
				      if(y-1==this->mWin->getLimitGauche()) y++;
                      else y--;
				break;
				case KEY_RIGHT:
				      if(y+1==this->mWin->getLimitDroit()) y--;
				      else y++;
				break;
				case 'Q':
					quitter=true; return 0;
				break;
				case 'q':
					quitter=true; return 0;
				break;
            }
         this->mWin->update(x,y);
         this->mJoueur->setPositionXY(x,y);//pour continuer la partie
         /*this->mJoueur->actionClavierText(key);
         this->mWin->update(this->mJoueur->getMPositionX(),this->mJoueur->getMPositionY());*/
         std::this_thread::sleep_for(std::chrono::milliseconds(1000/15));
//on pourra en suite demander a la mJoeur les derniers cordonnées enregistré pour continuer une partie
        }
        return -1;
}

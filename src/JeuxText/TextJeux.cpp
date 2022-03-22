#include "TextJeux.h"
#include<iostream>

TextJeux::TextJeux(): mQuit(false), mMenuText(&mWin), mAfficheJeux(&mWin) {
}
TextJeux::~TextJeux(){
     delete this->mTerrain;
}
int TextJeux::jouer(){


        MenuText::eAction action = MenuText::aucun;
        while (action != MenuText::quitter)
        {
            action = this->mMenuText.lireAction(false);
            switch (action)
	     	{
                //	Lancer une nouvelle partie
                case MenuText::nouveau:
                {
                    std::cout << "Nouvelle partie." <<std::endl;
                    this->nouvellePartie();
                }
                break;

                //	Continuer une partie
                case MenuText::continu:
                {
                    std::cout << "continuer" << std::endl;
                   /* if (this->partie.en_cours)
                        this->jouer();
                    else
                        this->continuer_sauvegarde();*/
                }
                break;

                //	Afficher l'aide
                case MenuText::aide:
                {
                    std::cout << "aide" << std::endl;
                    this->aide();
                }
                break;

                default:
                {	}
		}

    }

        return 0;
}
void TextJeux::nouvellePartie()
{
    int winLos=this->mAfficheJeux.lancePartie();
    std::string resultat="";
    if(winLos==1) resultat="Bravo vous etes arrive 1er";
    else if(winLos==2) resultat="Humm vous etes arrive 2eme";
    else if(winLos==3) resultat="Vous etes arrive 3eme";
    else return;
    int	key = 0;
	static std::vector<std::string> const	texte {
"                                       Resultat                                  ",
"=============================================================================",
"",
resultat+" de la course",
"=> Bonus : 40 ",
"=> Temps moyen par tours : 2mn:45",
"=> Vitesse maximale acquise: 70km/h",
"Appuyer sur m pour retourner au menu ou n pour une nouvelle partie"
	};
	this->mWin.effacer();
	for (int y = 0; y < 24 && y < (int)texte.size(); ++y)
		this->mWin.dessinerTxtCentre(y, texte[y].c_str());
	while (key != 'm' && key != 'M'){
	    key = getch();
		if(key=='n' || key=='N') {key='m'; this->nouvellePartie();}
	}

}
void TextJeux::aide()
{
	int	key = 0;
	static std::vector<std::string> const	texte {
"                                       Aide                                  ",
"=============================================================================",
"",
"Appuyer La fleche: ",
"=> UP pour accélérer ",
"=> RIGHT pour tourner a droite",
"=> LEFT pour tourner a gauche",
"=> DOWN pour décélérer",
"=> Apuiyer sur la touche q a tous moment du jeu pour revenir au menu principal",
"Appuyer sur m pour retourner au menu"
	};
	this->mWin.effacer();
	for (int y = 0; y < 24 && y < (int)texte.size(); ++y)
		this->mWin.dessinerTxtCentre(y, texte[y].c_str());
	while (key != 'm' && key != 'M')
		key = getch();
}

bool TextJeux::getMQuit() const { return mQuit; }
void TextJeux::setMQuit(bool quit) { mQuit = quit; }

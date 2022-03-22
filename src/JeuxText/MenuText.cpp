#include "MenuText.h"
#include <thread>
#include<iostream>



 MenuText::MenuText(WinText* win) : mWin(win) {}

 MenuText::eAction MenuText::lireAction(bool continuer){

	static std::vector<std::string> const menu1 {
		"Nouvelle Partie",
        "Choisir voiture",
		"Choisir piste",
		"Aide",
		"Quitter"
	};
	static std::vector<std::string> const menu2 {
		"Nouvelle Partie",
		"Continuer",
		"Aide",
		"Quitter"
	};
	int	key = 0;
	int	choix = 0;
	std::vector<std::string> const* menu = &menu1;

	if (continuer)
		menu = &menu2;
//
	while (key != 10 && key != KEY_ENTER)
	{
		this->afficheMenu(*menu, choix);
		key = getch();
		if (key == KEY_UP)
			--choix;
		if (key == KEY_DOWN)
			++choix;
		if (choix < 0)
			choix = menu->size() - 1;
		if (choix >= (int)menu->size())
			choix = 0;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000/15));
	}

	// a la sortie de la boucle on a le choix de l'utilisateur
	if ((*menu)[choix] == "Nouvelle Partie")
		return (eAction::nouveau);
	if ((*menu)[choix] == "Continuer")
		return (eAction::continu);
	if ((*menu)[choix] == "Aide")
		return (eAction::aide);

	return (eAction::quitter);
}

 void MenuText::afficheMenu(std::vector<std::string> const& menu, int choix){

	this->mWin->effacer();
	this->mWin->dessinerTxtCentre(1, "Menu Principal");

	for (unsigned int i = 0; i < (int)menu.size(); ++i)
	{
		std::string	entree = menu[i];

		if (i == choix)
			entree = "<< " + entree + " >>";
		this->mWin->dessinerTxtCentre(3 + i, entree.c_str());
	}
}

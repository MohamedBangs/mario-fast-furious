#include "MenuSdl.h"

#include<iostream>


MenuSdl::MenuSdl() {}

MenuSdl::~MenuSdl() {
    this->libereMemoire();
}

SDL_Texture * MenuSdl::loadImage(const char path[], SDL_Renderer * renderer, SDL_Rect & rect) {
  SDL_Surface * tmp = NULL;
  SDL_Texture * texture = NULL;
  tmp = IMG_Load(path);
  if (NULL == tmp) {
    fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    return NULL;
  }
  texture = SDL_CreateTextureFromSurface(renderer, tmp);
  rect.h = tmp -> h;
  rect.w = tmp -> w;
  SDL_FreeSurface(tmp);
  if (NULL == texture) {
    fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
    return NULL;
  }
  return texture;
}

void MenuSdl::menuPrincipale(std::string str, bool & continuer, SDL_Renderer * renderer){

  int decalage = 53; //decalage horizontal entre les buttons
  for (int i = 0; i < this -> nb; i++) {
    if (i == 1) {
         if(continuer){
               std::stringstream ss;
              ss << i + 1;
              str = ss.str();
              str = "data/images/btn" + str + ".png";
              this -> button[i] = this -> loadImage(str.c_str(), renderer, this -> rect[i]);
              this -> rect[i].x = 350;
              this -> rect[i].y = 100 + decalage;
              decalage += 53;
         }
    } else {
          std::stringstream ss;
          ss << i + 1;
          str = ss.str();
          str = "data/images/btn" + str + ".png";
          this -> button[i] = this -> loadImage(str.c_str(), renderer, this -> rect[i]);
          this -> rect[i].x = 350;
          this -> rect[i].y = 100 + decalage;
          decalage += 53;
    }

  }
}

MenuSdl::eAction MenuSdl::afficheMenu(SDL_Window * window, SDL_Renderer * renderer, Joueur * joueur, Terrain * terrain, std::map < std::string, std::string > & chainSprteIntel, bool & continuer) {

  std::string str;
  this -> fond = loadImage("data/images/fondmenu.jpg", renderer, rect[nb]);
  this -> titre = loadImage("data/images/titre.png", renderer, rect[nb]);
  this->emplacemntTitre={250, 5, this->rect[nb].w, this->rect[nb].h};
  this->menuPrincipale(str, continuer, renderer);
  bool running = true, retourpiste = false, retourmario = false, retouraide = false, sousmenu=false, retourniveau=false;
  int sourisX = 0, sourisY = 0, nbpiste = 3;
  while (running) {
    SDL_Event ev;
    while (SDL_PollEvent( & ev)) {
      switch (ev.type) {
      case SDL_QUIT:
        running = false;
        return (eAction::quitter);
        break;
      case SDL_MOUSEBUTTONUP:
        if (ev.button.button == SDL_BUTTON_LEFT) { //clic left

          sourisX = ev.button.x;
          sourisY = ev.button.y;
          for (int i = 0; i < nb; i++) {
            if (sourisX >= this -> rect[i].x && sourisX <= (this -> rect[i].x + this -> rect[i].w) &&
              sourisY >= this -> rect[i].y && sourisY <= (this -> rect[i].y + this -> rect[i].h)) {

              switch (i) {
              case 0: {
                if (retourpiste || retouraide) {
                  terrain -> setNom("data/images/piste1.bmp");
                  terrain->setTempsRequis(30);//30s minimum pour finir le tours de la piste 1
                  terrain->setBandeFinaleXmin(-146.252);
                  terrain->setBandeFinaleXmax(-30.56);
                  terrain->setBandeFinaleYmin(428.451);
                  terrain->setBandeFinaleYmax(437);
                  joueur -> setPositionXY(-68.5046, 300.954);
                  sousmenu=false; //dès qu'on clique sur choix dans le sous menu, alors on reviens sur l'accueil menu
                } else if (retourmario) {
                  joueur -> setNom("data/images/mario1.png");
                  chainSprteIntel["Joeur2"] = "data/images/mario2.png";
                  chainSprteIntel["Joeur3"] = "data/images/mario3.png";
                  sousmenu=false; //pareil
                }else if(retourniveau){
                    std::cout<<"niveau 1"<<std::endl;
                    sousmenu=false;
                }else {
                  running = false;
                  return (eAction::nouveau);
                }
                break;
                }
              case 1:{
                if (retourpiste) {
                  terrain -> setNom("data/images/piste2.bmp");
                  terrain->setTempsRequis(38);//38s minimum pour finir le tours de la piste 2
                  terrain->setBandeFinaleXmin(-682.71);
                  terrain->setBandeFinaleXmax(-608.35);
                  terrain->setBandeFinaleYmin(1052.62);
                  terrain->setBandeFinaleYmax(1056.24);
                  joueur -> setPositionXY(-644.93, 1014.24);
                  sousmenu=false;
                } else if (retourmario) {
                  joueur -> setNom("data/images/mario2.png");
                  chainSprteIntel["Joeur2"] = "data/images/mario1.png";
                  chainSprteIntel["Joeur3"] = "data/images/mario3.png";
                  sousmenu=false;
                }else if(retourniveau){
                    std::cout<<"niveau 2"<<std::endl;
                    sousmenu=false;
                } else {
                  running = false;
                  return (eAction::continu);
                }
                break;
                }
              case 2:
                {
                  if (retourpiste) {
                    terrain -> setNom("data/images/piste3.bmp");
                    terrain->setTempsRequis(33);//33s minimum pour finir le tours de la piste 3
                    terrain->setBandeFinaleXmin(-774.509);
                    terrain->setBandeFinaleXmax(-671.75);
                    terrain->setBandeFinaleYmin(871.939);
                    terrain->setBandeFinaleYmax(895.249);
                    joueur -> setPositionXY(-704.132, 842.974);
                    sousmenu=false;
                  } else if (retourmario) {
                    joueur -> setNom("data/images/mario3.png");
                    chainSprteIntel["Joeur2"] = "data/images/mario2.png";
                    chainSprteIntel["Joeur3"] = "data/images/mario1.png";
                    sousmenu=false;
                  }else if(retourniveau){
                    std::cout<<"niveau 3"<<std::endl;
                    sousmenu=false;
                  }else{
                     std::cout<<"choix de niveau"<<std::endl;
                      int decal = 100;
                      for (int i = 0; i < this -> nb; i++) {
                        if (NULL != this -> button[i])
                          SDL_DestroyTexture(this -> button[i]);
                      }
                      this -> nb = nbpiste;
                      for (int i = 0; i < this -> nb; i++) {
                        //on change les bouttons en mario
                        std::stringstream ss;
                        ss << i + 1;
                        str = "data/images/niveau" + ss.str() + ".png";
                        this -> button[i] = this -> loadImage(str.c_str(), renderer, this -> rect[i]);
                        this -> rect[i].x = 230;
                        this -> rect[i].y = 100 + decal;
                        this -> rect[i].h = this -> rect[i].h * 2;
                        this -> rect[i].w = this -> rect[i].w * 2;
                        decal += 53 * 3;
                      }
                         retourniveau=true;
                         sousmenu=true;
                      }
                  break;
                }
             case 3:{
                  //on affiche les pistes au joueur
                    int decal = 100;
                    for (int i = 0; i < this -> nb; i++) {
                      if (NULL != this -> button[i])
                        SDL_DestroyTexture(this -> button[i]);
                    }
                    this -> nb = nbpiste;
                    for (int i = 0; i < this -> nb; i++) {
                      //on change les bouttons en piste
                      std::stringstream ss;
                      ss << i + 1;
                      str = "data/images/piste" + ss.str() + ".jpeg";
                      this -> button[i] = this -> loadImage(str.c_str(), renderer, this -> rect[i]);
                      this -> rect[i].x = decal;
                      this -> rect[i].y = 150;
                      this -> rect[i].w = this -> rect[i].w / 4;
                      this -> rect[i].h = this -> rect[i].h / 4;
                      decal += rect[i].w +50;
                    }
                    sousmenu=true;
                    retourpiste = true;
                  break;
               }
              case 4:
                {
                  int decal = 50;
                  for (int i = 0; i < this -> nb; i++) {
                    if (NULL != this -> button[i])
                      SDL_DestroyTexture(this -> button[i]);
                  }
                  this -> nb = nbpiste;
                  for (int i = 0; i < this -> nb; i++) {
                    //on change les bouttons en mario
                    std::stringstream ss;
                    ss << i + 1;
                    str = "data/images/descript_mario" + ss.str() + ".png";
                    this -> button[i] = this -> loadImage(str.c_str(), renderer, this -> rect[i]);
                    this -> rect[i].x = 150;
                    this -> rect[i].y = 100 + decal;
                    this -> rect[i].h = this -> rect[i].h * 2;
                    this -> rect[i].w = this -> rect[i].w * 2;
                    decal += 53 * 2;
                  }
                  retourmario = true;
                  sousmenu=true;
                  break;
                }
              case 5:
                for (int i = 0; i < this -> nb; i++) {
                  if (NULL != this -> button[i])
                    SDL_DestroyTexture(this -> button[i]);
                }
                this -> nb = 1;
                  //on affiche l'aide
                this -> button[0] = this -> loadImage("data/images/aide.png", renderer, this -> rect[0]);
                this -> rect[0].x = 200;
                this -> rect[0].y = 150;
                this -> rect[0].h = this -> rect[0].h * 2;
                this -> rect[0].w = this -> rect[0].w * 2;
                retouraide = true;
                sousmenu=true;
                break;
              case 6:
                running = false;
                return (eAction::quitter);
                break;
              }
            }
          }//a près avoir executé l'action en question on verifie s'il fa

            if((retouraide || retourmario || retourpiste || retourniveau) && !sousmenu){
                //on efface l'ecran apres selection et on affiche le menu principale
                 for (int i = 0; i < this -> nb; i++) {
                       if (NULL != this -> button[i])
                        SDL_DestroyTexture(this -> button[i]);
                    }
                    this -> nb = 7;
                    this->menuPrincipale(str, continuer, renderer);
                    retouraide=false;
                    retourmario=false;
                    retourpiste=false;
                    retourniveau=false;
                    sousmenu=false;//on n'est au menu principale
            }
        }

        break;
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, this -> fond, NULL, NULL);
    SDL_RenderCopy(renderer, this -> titre, NULL, & emplacemntTitre);
    for (int i = 0; i < this -> nb; i++){
      if(!sousmenu && i==1)
      {
         if(continuer) //pour ne pas afficher la case[1] contenunant l'item continuer alors qu'on pas commencer a jouer
          SDL_RenderCopy(renderer, this -> button[i], NULL, & rect[i]);

      }else
       SDL_RenderCopy(renderer, this -> button[i], NULL, & rect[i]);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
  }
 // this -> libereMemoire();
   return (eAction::nouveau);// on veu quitte le jeux
}

void MenuSdl::libereMemoire() {

  for (int i = 0; i < this -> nb; i++) {
    if (NULL != this -> button[i])
      SDL_DestroyTexture(this -> button[i]);
  }
  if (NULL != this -> fond)
    SDL_DestroyTexture(this -> fond);
}

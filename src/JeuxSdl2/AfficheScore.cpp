#include "AfficheScore.h"

AfficheScore::AfficheScore(){}
AfficheScore::~AfficheScore(){
   this->libereMemoire();
}
void AfficheScore::afficheScoreApresPartie(SDL_Renderer * renderer, SdlJeuxUtil *sdlJeuxUtil){

//fond
  this -> fond = sdlJeuxUtil->loadImage("data/images/lifap4.png", renderer, rect[0]);
  int decalage = 53; //decalage horizontal entre les buttons
  //texte 'Partie Terminer'
  this -> element[0] = sdlJeuxUtil->loadImage("data/images/scores/parti_terminer.png", renderer, this -> rect[0]);
  this -> rect[0].x=100;
  this->rect[0].y=10;
  decalage += 120;

  //texte 'ordere d'arriver'
  this -> element[1] = sdlJeuxUtil->loadImage("data/images/scores/classement.png", renderer, this -> rect[1]);
  this -> rect[1].x=200;
  this->rect[1].y=decalage;

  //premier
   this -> element[2] = sdlJeuxUtil -> loadImage("data/images/scores/joueur1.png", renderer, this -> rect[2]);
   this -> rect[2].x = 350;
   this -> rect[2].y = 100 + decalage;
   decalage += 60;
     //deuxieme
   this -> element[3] = sdlJeuxUtil -> loadImage("data/images/scores/joueur2.png", renderer, this -> rect[3]);
   this -> rect[3].x = 350;
   this -> rect[3].y = 100 + decalage;
   decalage += 60;
  //troisieme
   this -> element[4] = sdlJeuxUtil -> loadImage("data/images/scores/joueur3.png", renderer, this -> rect[4]);
   this -> rect[4].x = 350;
   this -> rect[4].y = 100 + decalage;
   decalage += 170;
  //texte 'Meilleur Temps'
  this->element[5]=sdlJeuxUtil->loadImage("data/images/scores/meilleur_temps.png",renderer, this -> rect[5]);
   this->rect[5].x=200;
   this->rect[5].y=decalage;

   decalage+=60;
     //texte 'Temps'
  this->element[6]=sdlJeuxUtil->loadImage("data/images/scores/tour1.png",renderer, this ->rect[6]);
   this->rect[6].x=350;
   this->rect[6].y=decalage;
  //texte 'Joeurs'
  this->element[7]=sdlJeuxUtil->loadImage("data/images/scores/joueur1.png", renderer, this -> rect[7]);
   this->rect[7].x=this->rect[6].w+150;
   this->rect[7].y=decalage;

  decalage+=80;
  //texte 'Joeurs'
  this->element[8]=sdlJeuxUtil->loadImage("data/images/scores/retour.png", renderer, this -> rect[8]);
   this->rect[8].x=10;
   this->rect[8].y=decalage;

   bool running=true;
   int sourisX = 0, sourisY = 0;
   while (running) {
    SDL_Event ev;
    while (SDL_PollEvent( & ev)) {
      switch (ev.type) {
        case SDL_QUIT:{
            running = false;
            SDL_Window * tmp = SDL_GetWindowFromID(ev.window.windowID);
            this -> libereMemoire();
            SDL_DestroyWindow(tmp);
            break;
        }
        case SDL_MOUSEBUTTONUP:
            if (ev.button.button == SDL_BUTTON_LEFT) { //clic left
              sourisX = ev.button.x;
              sourisY = ev.button.y;
              if (sourisX >= this -> rect[8].x && sourisX <= (this -> rect[8].x + this -> rect[8].w) &&
              sourisY >= this -> rect[8].y && sourisY <= (this -> rect[8].y + this -> rect[8].h)) {
                   running=false;
              }
            }
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, this->fond, NULL, NULL);
    for (int i = 0; i < this -> nb; i++)
       SDL_RenderCopy(renderer, this -> element[i], NULL, & rect[i]);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
   }
}
void AfficheScore::libereMemoire(){
  for (int i = 0; i < this -> nb; i++) {
    if (NULL != this -> element[i])
      SDL_DestroyTexture(this -> element[i]);
  }
  if (NULL != this -> fond)
    SDL_DestroyTexture(this -> fond);
}

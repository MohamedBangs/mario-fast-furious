#include "AfficheJeuxSdl.h"

#include<iostream>

AfficheJeuxSdl::AfficheJeuxSdl(SDL_Window * p_window, SDL_Renderer * p_renderer, Joueur * p_joueur, Terrain * p_terrain,
    SdlJeuxUtil * p_SdlJeuxUtil): window(p_window), renderer(p_renderer), mJoueur(p_joueur),
  mTerrain(p_terrain), mSdlJeuxUtil(p_SdlJeuxUtil) {

    this -> mCamera = new Camera();
    this->mCollision=new Collision();
    this -> temps.difference = 0;
    this -> temps.tempsActuel = 0;
    this -> quitter = false;

    this -> initJeux();
}
AfficheJeuxSdl::~AfficheJeuxSdl() {
  this -> libereMemoire();
}

void AfficheJeuxSdl::lancePartie(bool & continuer, std::string & joueur2, std::string & joueur3, bool &finJeux) {

  if (!continuer) { //on veut pas continuer, on reivente l'interface pour nouvelle partie;
    //on crée les composant terains,joueur.. en fonction du choix dans le menu
    this -> renitialiseEtatJeux(joueur2, joueur3);

  } else this -> etatMusique(); //si non on lance le jeux là ou s'etait!!!

  for (unsigned int i = 1; i < 3; i++) {
    this -> animateur[i].x = 0;
    this -> animateur[i].y = 0;
    this -> animateur[i].w = 32;
    this -> animateur[i].h = 32;
  }
  this -> mCamera -> update();
  this -> onJoue(finJeux);
  continuer = true; //après le jeux l'option continue doit etre disponible dans le menu

}
void AfficheJeuxSdl::renitialiseEtatJeux(std::string jouer2, std::string Joueur3) {

  if(NULL == (this -> tmpPl = SDL_LoadBMP(this -> mTerrain -> getNom().c_str())) ||
    NULL == (this -> piste = SDL_CreateTexture(this -> renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, SdlJeuxUtil::screenW, SdlJeuxUtil::screenH)) ||
    NULL == (this -> sprite = this -> mSdlJeuxUtil -> loadImage(this -> mJoueur -> getNom().c_str(), renderer)) ||
    NULL == (this -> sprite2 = this -> mSdlJeuxUtil -> loadImage(jouer2.c_str(), renderer)) ||
    NULL == (this -> sprite3 = this -> mSdlJeuxUtil -> loadImage(Joueur3.c_str(), renderer)) ||
    NULL == (this -> pisteLogique = SDL_ConvertSurfaceFormat(this -> tmpPl, SDL_PIXELFORMAT_RGBA32, 0)) ||
    NULL == (this -> textureRetourMenu = this -> mSdlJeuxUtil -> loadImage("data/images/mario.png", renderer, this -> rectRetourMenu))
  ) {
    this -> libereMemoire();//on quitte le jeux en cas d'erreur l'ors de l'initialisation
  }
  this -> mCamera -> re_init();
  this->mCamera->setPositionX(this->mJoueur->getPositionX());
  this->mCamera->setPositionY(this->mJoueur->getPositionY());
  this -> mJoueur -> setDeceleration(0);
  this -> temps.difference = SDL_GetTicks();
  Mix_PlayMusic(this -> musique, -1); //Jouer infiniment la musique
  Mix_ResumeMusic(); //Reprendre la musique

}

void AfficheJeuxSdl::initJeux() {

  if (0 != this -> mSdlJeuxUtil -> initLibrary()) {
    this -> libereMemoire();
  }
  this -> police = TTF_OpenFont("data/texte/LinLibertine_aDRS.ttf", 30);
  TTF_SetFontStyle(this -> police, TTF_STYLE_BOLD);

  this -> surfVitesse = TTF_RenderText_Solid(this -> police, "0 km/h", this -> couleurRouge);
  this -> surfTemps = TTF_RenderText_Solid(this -> police, "Temps : 0 s", this -> couleurRouge);

  this -> textureVitesse = SDL_CreateTextureFromSurface(this -> renderer, this -> surfVitesse);
  this -> textureTemps = SDL_CreateTextureFromSurface(this -> renderer, this -> surfTemps);
  //rect vitesse
  this -> rectVitesse.x = SdlJeuxUtil::screenW * SdlJeuxUtil::pxs - 200;
  this -> rectVitesse.y = 20;
  this -> rectVitesse.w = this -> surfVitesse -> w; //ici le probleme
  this -> rectVitesse.h = this -> surfVitesse -> h;

  // rect temps
  this -> rectTemps.x = SdlJeuxUtil::screenW * SdlJeuxUtil::pxs - 200;
  this -> rectTemps.y = 50;
  this -> rectTemps.w = this -> surfTemps -> w;
  this -> rectTemps.h = this -> surfTemps -> h;

  //la musique
  Mix_VolumeMusic(MIX_MAX_VOLUME); //Mettre le volume à fond
  this -> musique = Mix_LoadMUS("data/musique_son/music.mp3"); //Chargement de la musique

  //le son
  Mix_AllocateChannels(2); //Allouer 2 canaux
  Mix_Volume(1, MIX_MAX_VOLUME / 8); //Mettre à moitié le post 1

  this -> son = Mix_LoadWAV("data/musique_son/1111.wav"); //Charger un wav dans un pointeur
  Mix_VolumeChunk(this -> son, MIX_MAX_VOLUME); //Mettre un volume pour ce wav

  this -> rectRetourMenu.x = 10;
  this -> rectRetourMenu.y = 10;
  //rect pour animer le joueur les marios on tous (33:33) comme size
  //0=>pour le joueur principale
  this -> animateur[0].h = 33;
  this -> animateur[0].w = 33;
  this -> animateur[0].y = 0;
  this -> animateur[0].x = 0;
  //position du jour par defaut pour le terrain par default
  this -> mJoueur -> setPositionXY(-68.5046, 300.954);
  //1-4 pour l'intelligence artificielle
  for (unsigned int i = 1; i < 3; i++) {
    this -> animateur[i].h = SdlJeuxUtil::spriteH;
    this -> animateur[i].w = SdlJeuxUtil::spriteW;
  }
}

void AfficheJeuxSdl::onJoue(bool &finJeux) {

  const Uint8 * keys = SDL_GetKeyboardState(NULL);
  Uint32 animJoueur1 = 0;
  int decimalVitesse=0;
  while (!this -> quitter) {
    SDL_Event ev;
    while (SDL_PollEvent( & ev)) {
      switch (ev.type) {

      case SDL_QUIT:
        {
          this -> quitter = true;
          SDL_Window * tmp = SDL_GetWindowFromID(ev.window.windowID);
          this -> libereMemoire();
          SDL_DestroyWindow(tmp);
          break;
        }
      case SDL_MOUSEBUTTONUP:
        if (ev.button.button == SDL_BUTTON_LEFT) { //clic left
          if (ev.button.x >= this -> rectRetourMenu.x && ev.button.x <= (this -> rectRetourMenu.x + this -> rectRetourMenu.w) &&
            ev.button.y >= this -> rectRetourMenu.y && ev.button.y <= (this -> rectRetourMenu.y + this -> rectRetourMenu.h)) {
            //le joueur à cliquer sur le button pause
            this -> temps.difference = (unsigned int) SDL_GetTicks(); //pour retrouver le temps quand on veut continuer
            Mix_PauseMusic(); //Mettre en pause la musique;
            this -> quitter = true;
          }
        }
        break;

      }
    }
    if (keys[SDL_SCANCODE_P]) {
      this -> etatMusique();
    }
    if (keys[SDL_SCANCODE_LEFT]) {
      this -> mCamera -> setDirection(1);
      Uint32 ticks = SDL_GetTicks();
      animJoueur1 = (ticks / 150) % 3;
      this -> animateur[0].x = 32 * animJoueur1;
      this->mJoueur->setMoveLeftRight(1, -1);
    }
    if (keys[SDL_SCANCODE_RIGHT]) {
      this -> mCamera -> setDirection(-1);
      Uint32 ticks = SDL_GetTicks();
      animJoueur1 = (ticks / 100) % 3;
      this -> animateur[0].x = 32 * animJoueur1;
      this->mJoueur->setMoveLeftRight(-1, 1);
    }

    if (keys[SDL_SCANCODE_UP]) {
      this -> mCamera -> setPositionY(cosf(this -> mCamera -> getDirection() * (M_PI / 180)));
      this -> mCamera -> setPositionX(-sinf(this -> mCamera -> getDirection() * (M_PI / 180)));
      this -> mJoueur -> setDeceleration(-0.03); //multiplié par temps d'affichage augmente la vitesse
      Mix_PlayChannel(1, son, 0); //Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1)
      this -> animateur[0].x = 0;
    }

    if (keys[SDL_SCANCODE_DOWN]) {
      /*this->mCamera->setPositionY(-cosf(this->mCamera->getDirection() * (M_PI / 180)));
      this->mCamera->setPositionX(sinf(this->mCamera->getDirection() * (M_PI / 180)));*/
      this -> mJoueur -> setDeceleration(1.0); //la touche bas deceler a 0.02
    }

    if(this -> mJoueur -> getJeJoue()) {
      this -> mJoueur -> setDeceleration(0.001);
      //on peut rouler la vitesse minimale n'est pas atteinte
      this -> mCamera -> setPositionY(cosf(this -> mCamera -> getDirection() * (M_PI / 180)));
      this -> mCamera -> setPositionX(-sinf(this -> mCamera -> getDirection() * (M_PI / 180)));
    }
    //mise a jour camera
    this -> mCamera -> update();
  //  std::cout<<"x=="<<this->mCamera->getPositionX()<<":y=="<<this->mCamera->getPositionY()<<std::endl;
    /*Uint32 pixel=this->mSdlJeuxUtil->obtenirPixel(this->pisteLogique, this->mCamera->getPositionX(), this->mCamera->getPositionY());
  std::cout<<pixel<<std::endl;*/
    //netoye le renderer
    SDL_SetRenderDrawColor(this -> renderer, 100, 100, 255, 0);
    SDL_RenderClear(this -> renderer);
    int * tdata = (int * ) this -> pisteLogique -> pixels;
    for (int y = 0; y < SdlJeuxUtil::screenH; y++) {
      float v = 1.f - ((float) y / (float) SdlJeuxUtil::screenH);
      Camera::Line inter = this -> mCamera -> getProjected(v);
      for (int x = 0; x < SdlJeuxUtil::screenW; x++) {
        float u = (float) x / (float) SdlJeuxUtil::screenW;

        Camera::IPoint coord = this -> mCamera -> getTexCoords(u, inter, this -> pisteLogique -> w, this -> pisteLogique -> h);

        this -> buffer[y][x] = tdata[coord.y * (this -> pisteLogique -> pitch / 4) + coord.x];
      }
    }
    if(this->mCollision->collisionJoueurTerrainGauche(this->mJoueur->getMoveLeft())){
       // std::cout<<"collision gauche"<<std::endl;
		this->mJoueur->setMoveLeftRight(-1, 0);
		//this -> mCamera -> setDirection(-1.f);
	 }
	if(this->mCollision->collisionJoueurTerrainDroite(this->mJoueur->getMoveRight())){
       // std::cout<<"collision droite"<<std::endl;
		this->mJoueur->setMoveLeftRight(0, -1);
		//this -> mCamera -> setDirection(1.f);
    }
    SDL_FreeSurface(this -> surfVitesse); // On supprime la surface précédente
    SDL_DestroyTexture(this -> textureVitesse); // on detruit aussi sa texture

    this -> temps.tempsActuel = SDL_GetTicks() - this -> temps.difference;
    if(this -> mJoueur -> getDeceleration()<0)
         decimalVitesse=this -> mJoueur -> getDeceleration()*(-10);
    else
         decimalVitesse=this -> mJoueur -> getDeceleration()*(10);
    sprintf(this -> charVitesse, "%d km/h", decimalVitesse); // On écrit dans la chaîne "vit" la nouvelle vitesse
    sprintf(this -> charTemps, "temps : %d s", (int) this -> temps.tempsActuel / 1000); // On écrit dans le tableau "chartemps" le nouveau temps

    //on met a jour l'afffichage vittesse et temps ecoulé
    this -> surfVitesse = TTF_RenderText_Solid(this -> police, this -> charVitesse, this -> couleurRouge);
    this -> surfTemps = TTF_RenderText_Solid(this -> police, this -> charTemps, this -> couleurRouge);

    this -> textureVitesse = SDL_CreateTextureFromSurface(this -> renderer, this -> surfVitesse);
    this -> textureTemps = SDL_CreateTextureFromSurface(this -> renderer, this -> surfTemps);
    SDL_UpdateTexture(this -> piste, NULL, this -> buffer, SdlJeuxUtil::screenW * 4);
    SDL_RenderCopy(this -> renderer, this -> piste, NULL, & this -> vueTerrain);
    SDL_RenderCopy(this -> renderer, this -> sprite, & this -> animateur[0], & this -> vueJoueur);
    //intelligence artificielle
    if( ((int) this -> temps.tempsActuel / 1000) < 4 && this->mJoueur->getDeceleration() > 0 ){
        SDL_RenderCopy(this -> renderer, this -> sprite2, & this -> animateur[1], & this -> vueJoueur2);
        SDL_RenderCopy(this -> renderer, this -> sprite3, & this -> animateur[2], & this -> vueJoueur3);
    }

    SDL_RenderCopy(this -> renderer, this -> textureVitesse, NULL, & this -> rectVitesse);
    SDL_RenderCopy(this -> renderer, this -> textureTemps, NULL, & this -> rectTemps);
    SDL_RenderCopy(this -> renderer, this -> textureRetourMenu, NULL, & this -> rectRetourMenu);
    SDL_RenderPresent(this -> renderer);
    SDL_Delay(SdlJeuxUtil::vitesseMinimaleJeux + this -> mJoueur -> getDeceleration());
    //fin de jeux ou  pas?
    finJeux=this->finDuJeux();
  }
  //apres le jeux on met en pause la musique
  Mix_PauseMusic();
  this -> quitter = false; //pour ne pas quitter le jeux l'orsqu'on retourne au menu principale;

}

bool AfficheJeuxSdl::finDuJeux(){

  if( ((int) this -> temps.tempsActuel / 1000) >= this->mTerrain->getTempsRequis() &&
        this->mCamera->getPositionX() >= this->mTerrain->getBandeFinaleXmin() &&
        this->mCamera->getPositionX() <= this->mTerrain->getBandeFinaleXmax() &&
        this->mCamera->getPositionY() >= this->mTerrain->getBandeFinaleYmin() &&
        this->mCamera->getPositionY() <= this->mTerrain->getBandeFinaleYmax() ){
        if(this->mJoueur->getNombreTour() >= 2 && ((int) this -> temps.tempsActuel / 1000) >= this->mTerrain->getTempsRequis()*2){
             /*le joueur a fait deux tours et que le nombre de secondes a > fois le nombre de seconde requise
             alors il a fini la partie
             this->mJoueur->getNombreToure() >= 2 par ce que les machines actuelles sont minu de plusieur coeurs, du coup
             cette fonction peut etre executé n-fois l'orsque le premier if est execute */
             this->quitter=true;
             Mix_PauseMusic(); //Mettre en pause la musique;
             return true;
        }
        this->mJoueur->setNombreTour(1);
    }
    return false;
}

void AfficheJeuxSdl::libereMemoire() {
  delete this -> mCamera;
  delete this->mCollision;
  if (NULL != this -> sprite)
    SDL_DestroyTexture(this -> sprite);
  if (NULL != this -> sprite2)
    SDL_DestroyTexture(this -> sprite2);
  if (NULL != this -> sprite3)
    SDL_DestroyTexture(this -> sprite3);
  if (NULL != this -> piste)
    SDL_DestroyTexture(this -> piste);
  if (NULL != this -> tmpPl)
    SDL_FreeSurface(this -> tmpPl);
  if (NULL != this -> textureRetourMenu)
    SDL_DestroyTexture(this -> textureRetourMenu);
  if (NULL != this -> surfVitesse)
    SDL_FreeSurface(this -> surfVitesse);
  if (NULL != this -> surfTemps)
    SDL_FreeSurface(this -> surfTemps);
  if (NULL != this -> textureVitesse)
    SDL_DestroyTexture(this -> textureVitesse);
  if (NULL != this -> textureTemps)
    SDL_DestroyTexture(this -> textureTemps);
  Mix_FreeMusic(this -> musique); //Libération de la musique
  Mix_FreeChunk(this -> son); //Libération du son
  TTF_CloseFont(this -> police);
  TTF_Quit();
  Mix_CloseAudio();
  SDL_Quit();
  exit(0);
}
void AfficheJeuxSdl::etatMusique() {

  if (Mix_PausedMusic() == 1) { //Si la musique est en pause
    Mix_ResumeMusic(); //Reprendre la musique
  } else {
    Mix_PauseMusic(); //Mettre en pause la musique
    //Mix_HaltChannel(-1); //On arrête tous les canaux
  }
}

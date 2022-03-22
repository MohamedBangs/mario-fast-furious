#include "SdlJeuxUtil.h"

int SdlJeuxUtil::init(SDL_Window **window, SDL_Renderer **renderer, int w, int h)
{

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }
    if(0 != SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN, window, renderer))
    {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
}

int SdlJeuxUtil::initLibrary(){

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur TTF_Init : %s\n", TTF_GetError());
        return -1;
    }

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        fprintf(stderr, "Erreur Mix_OpenAudio : %s\n", Mix_GetError());
        return -1;
    }
    return 0;
}

SDL_Texture * SdlJeuxUtil::loadImage(const char path[], SDL_Renderer *renderer)
{
//je dois tous les images en une , comme ça animer chaque npixels de l'image (piste,nature..) celà pertrat de charger une seule
//image par element et la manipuler dans la boucle
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = IMG_Load(path);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}
//surcharger de loadImage
SDL_Texture * SdlJeuxUtil::loadImage(const char path[], SDL_Renderer * renderer, SDL_Rect & rect) {
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

Uint32 SdlJeuxUtil::obtenirPixel(SDL_Surface *surface, int x, int y)
{
    /*nbOctetsParPixel représente le nombre d'octets utilisés pour stocker un pixel.
    En multipliant ce nombre d'octets par 8 (un octet = 8 bits), on obtient la profondeur de couleur
    de l'image : 8, 16, 24 ou 32 bits.*/
    int nbOctetsParPixel = surface->format->BytesPerPixel;
    //cout<<"nombre pixel =="<<nbOctetsParPixel<<endl;
    /* Ici p est l'adresse du pixel que l'on veut connaitre */
    /*surface->pixels contient l'adresse du premier pixel de l'image*/
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * nbOctetsParPixel;

    /*Gestion différente suivant le nombre d'octets par pixel de l'image*/
    switch(nbOctetsParPixel)
    {
        case 1:
            return *p;

        case 2:
            return *(Uint16 *)p;

        case 3:
            /*Suivant l'architecture de la machine*/
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;

        case 4:
            return *(Uint32 *)p;

        /*Ne devrait pas arriver, mais évite les erreurs*/
        default:
            return 0;
    }
}

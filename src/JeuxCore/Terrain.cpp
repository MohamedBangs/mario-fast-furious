#include"Terrain.h"

Terrain::Terrain(int dimx,int dimy){
  this->dimensionX=dimx;
  this->dimensionY=dimy;
}
Terrain::Terrain(){
    this->nom="data/images/piste1.bmp";//terrain par defaut
    //informations par defaut pour la piste une
    this->setTempsRequis(30);//30s minimum pour finir le tours de la piste 1
    this->setBandeFinaleXmin(-146.252);
    this->setBandeFinaleXmax(-30.56);
    this->setBandeFinaleYmin(428.451);
    this->setBandeFinaleYmax(437);
}

int Terrain::getTempsRequis() const {
    return this->infos.tempsRequis;
}
void Terrain::setTempsRequis(int tr){
    this->infos.tempsRequis=tr;
}
float Terrain::getBandeFinaleXmin() const{
    return this->infos.bandeFinaleXmin;
}
void Terrain::setBandeFinaleXmin(float bfxmin){
    this->infos.bandeFinaleXmin=bfxmin;
}
float Terrain::getBandeFinaleXmax() const{
    return this->infos.bandeFinaleXmax;
}
void Terrain::setBandeFinaleXmax(float bfxmax){
    this->infos.bandeFinaleXmax=bfxmax;
}
float Terrain::getBandeFinaleYmin()const{
    return this->infos.bandeFinaleYmin;
}
void Terrain::setBandeFinaleYmin(float bfymin){
    this->infos.bandeFinaleYmin=bfymin;
}
float Terrain::getBandeFinaleYmax()const{
    return this->infos.bandeFinaleYmax;
}
void Terrain::setBandeFinaleYmax(float bfymax){
    this->infos.bandeFinaleYmax=bfymax;
}
int Terrain::getDimensionX () const { return dimensionX; }
void Terrain::setDimensionX (int x) { dimensionX=x; }

int Terrain::getDimensionY () const { return dimensionY; }
void Terrain::setDimensionY (int y) { dimensionY=y; }

std::string Terrain::getNom()const { return this->nom;}
void Terrain::setNom(std::string nm){ this->nom=nm; }

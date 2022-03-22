#include "WinText.h"
//#include <cassert>
#include <cstring>

WinText::WinText()
{
    initscr();
    keypad(stdscr, true);
    leaveok(stdscr, false);
	raw();
	noecho();
	nodelay(stdscr, false);
	scrollok(stdscr, true);
	curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN,   COLOR_BLACK);
    init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
    this->position[0].x = LINES / 3;
    this->position[0].y = COLS /2;
	//this->effacer();
}

WinText::~WinText()
{
	curs_set(2);
	noraw();
	echo();
    endwin();
    delwin(this->boiteJoeur);
}
void WinText::init(int px, int py){
     this->initPlayeur(px, py);
     this->initTerrain();
}
void WinText::initPlayeur(int px, int py){
    //joueur
    this->masqueJoeur= subwin(stdscr, 3, 2, this->position[0].x, this->position[0].y);
    this->boiteJoeur= subwin(stdscr, 3, 2, px, py);
    wborder(this->boiteJoeur, '|', '|', ' ', ' ', ' ', ' ', '+', '+');
    wborder(this->masqueJoeur, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //intelligence artificiel
    this->intelArtificiel[0]= subwin(stdscr, 3, 2, px, py - 10);
    this->intelArtificiel[1]= subwin(stdscr, 3, 2, px-14, py);
    wborder(this->intelArtificiel[0], '|', '|', ' ', ' ', ' ', ' ', '+', '+');
    wborder(this->intelArtificiel[1], '|', '|', ' ', ' ', ' ', ' ', '+', '+');

    wbkgd(this->boiteJoeur, COLOR_PAIR(1));
    wbkgd(this->intelArtificiel[0], COLOR_PAIR(2));
    wbkgd(this->intelArtificiel[1], COLOR_PAIR(3));

    wrefresh(this->boiteJoeur);
    wrefresh(this->masqueJoeur);
    wrefresh(this->intelArtificiel[0]);
    wrefresh(this->intelArtificiel[1]);
    this->position[0].x=px;
    this->position[0].y=py;
}
void WinText::initTerrain(){

//affiche le circuit de course
    int mx=COLS/3;
    for(unsigned int i=0; i<COLS; i++){
	     for(unsigned int j=0; j<LINES; j++){
               mvprintw(j, i, "|");
		       refresh();
	     }
	     if(i==mx) i=(COLS/2)+10;
    }
}

void WinText::update(int px,int py){

	mvwin(this->masqueJoeur,this->position[0].x,this->position[0].y);
	wrefresh(this->masqueJoeur);

    mvwin(this->boiteJoeur,px,py);
	wrefresh(this->boiteJoeur);

    wrefresh(this->intelArtificiel[0]);
    wrefresh(this->intelArtificiel[1]);

	//le masque s'affichera au prochain tour a l'ancien emplacement du joueur!
    this->position[0].x=px;
    this->position[0].y=py;
}

void WinText::bougeIntelgenceArtificiel(){
        //coordonnees depart jour
    this->position[1].x=LINES / 3;
    this->position[1].y=COLS /2;
}

void WinText::effacer()
{
	clear();
}

void WinText::dessiner(int x_, int y_, char car_)
{
	mvaddch(y_, x_, car_);
}

void WinText::dessinerTxt(int x_, int y_, char const* txt_)
{
	for (int i = 0; txt_[i]; ++i)
		this->dessiner(x_ + i, y_, txt_[i]);
}

void WinText::dessinerTxtCentre(int y_, const char* txt_)
{
	this->dessinerTxt((80 - strlen(txt_)) / 2, y_, txt_);
}

void WinText::afficher()
{
	move(0, 0);
	refresh();
}
int WinText::getNbLigneScreen(){ return LINES; }
int WinText::getNbColsScreen(){ return COLS; }
int WinText::getLimitDroit(){ return (COLS/2) + 10; }
int WinText::getLimitGauche(){ return COLS/3; }

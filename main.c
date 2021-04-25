#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "personne.c"
#include "background.c"
#include "update_score.c"
#include "vie.c"
#include "obstacle.c"
#include "temps.c"
#include "ennemi.c"
#include "potion.c"

//#include "save.c"
//#include "collision.c"
//#include "enigme.c"


/*************************************************************  INTEGRATION  *************************************************************/


int main(int argc, char *argv[])
{

/*declarations des variables */

//menu m;
background bg; temps t;
score s; vie v; int valeur_score=0; int nb_potion=0; int potion0=1;
int potion1=2;int potion2=3;int potion3=4;int potion4=5;int potion5=6;int potion6=7;int potion7=8;int potion8=9;int potion9=10;


personnage p; obstacle o1,o2,o3; //collision c;
int touche=1; 
int sens=0;
// les Enigmes 
//enigme e1,e2,e3,e4,e5,e6;
int done=0; // lorsqu'on clique sur le clavier 
// Ennemis 
ennemi en1,en2;
int ennemi1=1;
int ennemi2=2;


/*
int i=0;// Quand  le menu est dans son etat initiale : pas de clic sur aucun des boutons. 
//JEU 
int i=1; // lorsqu'on commence le jeu
	/* Declaration des SDLs */

SDL_Surface *ecran=NULL;
SDL_Rect *position_ecran;
SDL_Event event; 


/*---------------------------------------------------------------- INITIALISATION ---------------------------------------------------------------- */ 

// fenetre et ecran

 SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
 TTF_Init();
 SDL_EnableKeyRepeat(100,100); //Fonctions de la SDL permettant d'initialiser la fenêtre

    ecran = SDL_SetVideoMode(1600,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
    SDL_WM_SetCaption("Land Of Gargoyls", NULL);


// les fonctions 

//initialiser_menu(&m);
initialiser_background(&bg);
initialiser_personnage(&p);
initialiser_temps(&t);
initialiser_vie(&v);
initialiser_score (valeur_score, &s );

initialiser_obstacle1(&o1);
initialiser_obstacle2(&o2);
initialiser_obstacle3(&o3);

initialiser_ennemi1(&en1);
initialiser_ennemi2(&en2);

initialiser_potion();


//enigme
//initialiser_enigme(&e1);
//initialiser_enigme(&e2);






/*---------------------------------------------------------------- DISPLAY ----------------------------------------------------------------*/

// la boucle du jeu 
 while (!done)
{ 

/*if (i==0) // lorsqu'on est dans le menu
	{afficher_menu(m,ecran);}
if (i==1) // lorsq'on est dans le jeu
	{*/
afficher_background(bg,ecran);
 
afficher_obstacle1(o1,ecran);
afficher_obstacle2(o2,ecran);
afficher_obstacle3(o3,ecran);
if(ennemi1)
afficher_ennemi1(en1,ecran);
if(ennemi2)
afficher_ennemi2(en2,ecran);
if (potion4)
afficher_potion4(ecran);
if (potion0)

TTF_Quit();
SDL_Quit();
   
 return EXIT_SUCCESS;
}

#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL_ttf.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"


typedef struct minimap
{ 
	SDL_Surface* s ;
	SDL_Rect position ;
	SDL_Surface* image;
	SDL_Rect rect ;
}minimap ; 

typedef struct curseur
{ 
	SDL_Surface* cu ;
	SDL_Rect position ;
}curseur ; 

typedef struct monguela{
	 SDL_Surface *texte;
	 SDL_Surface *bord;
	 SDL_Rect position;
	 SDL_Rect positionbord;
	 TTF_Font *police;
	 SDL_Color couleurNoire;
	 SDL_Color couleurBlanche;
	 int tempsActuel;
	 int tempsPrecedent ;
	 int compteur ;
	 char temps[20];
	 int fph;
	 int fps;
	 int fpm;
	 float dt;
}monguela;





minimap initialisation_minimap (minimap m) ;

curseur initialisation_curseur (curseur c) ; 

void afficher_minimap(minimap m,curseur c,SDL_Surface *ecran);


void mini_map(curseur * c ,minimap *m);
void mini_map1(curseur * c ,minimap *m);

void initialisation_monguela(monguela *t);
void afficher_monguela(monguela *t,SDL_Surface *ecran);

SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y);
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage);






#endif


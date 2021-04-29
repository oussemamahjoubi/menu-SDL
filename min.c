#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>// librairies qui contient les fonctions
#include <SDL/SDL_ttf.h>
#include "struct.h"
#include <SDL/SDL_mixer.h>

minimap initialisation_minimap (minimap m) 
{
	
	m.s=IMG_Load("minimap.png");	
	m.position.x=0 ;
	m.position.y=0 ;
	m.image= IMG_Load("2.png");//perso
	m.rect.x=190;
	m.rect.y=550;
return m ;
}

curseur initialisation_curseur(curseur c)
{
	c.cu=IMG_Load("minirajel.png");
	c.position.x=0;
	c.position.y=0;
	return c ;

}
void afficher_minimap(minimap m,curseur c,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.s,NULL,ecran,&m.position);
	SDL_BlitSurface(m.image,NULL,ecran,&m.rect);

	SDL_BlitSurface(c.cu,NULL,ecran,&c.position);

}


void mini_map(curseur * c ,minimap *m)
{
       c->position.x=(float)0.32*(m->rect.x);
	c->position.y=(float)0.32*(m->rect.y);


}









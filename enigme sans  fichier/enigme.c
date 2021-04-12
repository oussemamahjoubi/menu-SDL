#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"

void init_enigme(Imm * e)
{
	e->pos.x=0;
	e->pos.y=0;	
	e->srf=NULL;
}
//
void load_enigme(Imm * screen  , char image [],Imm *e,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"%d.jpg",*alea);
e->srf = IMG_Load(image);
 SDL_BlitSurface(e->srf,NULL,screen->srf,&(e->pos)) ;
  SDL_Flip(screen->srf) ;
}
 
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
     solution =3 ;
 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		solution =1;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution =2;	
 	}
 	return solution;
 }
//verifier reponse
int check_input_enigme(int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
			    }
       break ;          
	}
  return r ;
}
 //affichage resultat enigme
 void display_enigme(Imm * screen,int s,int r,Imm *en)
 {
 
 	if (r==s)
 	{
 		en->srf=IMG_Load("00.jpg");
 		SDL_BlitSurface(en->srf, NULL, screen->srf, &(en->pos)) ;
        SDL_Flip(screen->srf);
 	}
 	else
 	{
 		en->srf=IMG_Load("11.jpg");
 		SDL_BlitSurface(en->srf, NULL, screen->srf, &(en->pos)) ;
        SDL_Flip(screen->srf);
 	}
 }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL_ttf.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"struct.h"

void initialisation_monguela(monguela *t){

  t->texte = NULL;
  t->bord=NULL;
  t->police = NULL;

  t->couleurNoire.r=90;
  t->couleurNoire.g=100;
  t->couleurNoire.b=0;

  t->couleurBlanche.r=0;
  t->couleurBlanche.g=0;
  t->couleurBlanche.b=0;

  t->tempsActuel = 0;
  t->tempsPrecedent = 0;
  t->compteur = 0;
  sprintf(t->temps,"test");
  t->fph=0;
  t->fps=0;
  t->fpm=0;

  t->police = TTF_OpenFont("goods.ttf", 14);
  t->position.x = 73;
  t->position.y = 96;
  t->positionbord.x = 30;
  t->positionbord.y = 5;
  t->bord=IMG_Load( "bord.png" );
  t->tempsActuel = SDL_GetTicks();
  sprintf(t->temps,"TIME  %d - %d - %d",t->fph,t->fpm,t->fps-(60*t->fpm));
  t->texte = TTF_RenderText_Shaded(t->police, t->temps, t->couleurNoire, t->couleurBlanche);


}
void afficher_monguela(monguela *t,SDL_Surface *ecran)
{

    t->tempsActuel = SDL_GetTicks();
    t->dt=t->tempsActuel - t->tempsPrecedent;

    if ( t->dt >= 1000)
    {
      t->compteur += 1000;

      t->fps=t->compteur/1000;

      if (t->fps>59)
       { t->fpm=(t->fps/60);
                  //  maybe fps=fps-(60*fpm);

         if(t->fpm>59)
          t->fph=(t->fpm/60);


      }
      sprintf(t->temps,"TIME  %d - %d - %d",t->fph,t->fpm,t->fps-(60*t->fpm)); 


           /* On écrit la chaîne temps dans la SDL_Surface */
              // texte = TTF_RenderText_Solid(police, temps, couleurNoire);
      SDL_FreeSurface(t->texte);
      t->texte = TTF_RenderText_Shaded(t->police, t->temps, t->couleurNoire, t->couleurBlanche);


      t->tempsPrecedent = t->tempsActuel; 
    }


    SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); 

    SDL_BlitSurface(t->bord, NULL, ecran, &(t->positionbord)); 

    SDL_Flip(ecran);



}


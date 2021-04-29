#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "struct.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int main (void)

{
  int continuee=1;

  SDL_Surface *ecran =NULL;

  SDL_Surface *image=NULL;

  SDL_Rect posimage;

  SDL_Event event ; 
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Surface *back1,*back2; 

  image=IMG_Load( "mapmini1.png" );
  back2=IMG_Load( "mapmini2.png" );
  int x,xx=0 ;
  minimap m ;
  curseur c;
  monguela t;

  ecran = SDL_SetVideoMode(1280,720,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("oroboros", NULL);
  TTF_Init();
  initialisation_monguela(&t);

 // image= IMG_Load("map.png");
  posimage.x=0;
  posimage.y=0;

/////////////////////////////////////////////////////////////////////////////	
  if (ecran==NULL)
  {
    printf("error: %s ",SDL_GetError());
    exit(EXIT_FAILURE);
  }

  c=initialisation_curseur(c);
  m=initialisation_minimap(m);	
  while (continuee)
  {
    SDL_PollEvent(&event) ; 
    switch  ( event.type )  
    { 
     case  SDL_QUIT : 
     continuee  =  0 ; 
     break;
     case SDL_KEYDOWN : 
     switch( event.key.keysym.sym ){
       case  SDLK_UP :
c.position.y+=5;
       SDL_BlitSurface(image, NULL, ecran, &posimage);
        mini_map(&c ,&m) ;
        xx=detectCollPP (back2,m.rect) ;
       afficher_minimap(m,c,ecran);
        if(xx==1)
        {
          m.rect.y=m.rect.y-10;
         c.position.y=c.position.y-1;
        }
      
       SDL_Flip(ecran); 
       break;
       case  SDLK_DOWN :
c.position.y-=5;
       xx=detectCollPP(back2,m.rect) ;
        mini_map(&c ,&m) ;
       SDL_BlitSurface(image, NULL, ecran, &posimage);
       
       afficher_minimap(m,c,ecran);
       if(xx==1)
        {
         m.rect.y=m.rect.y-10;
         c.position.y=c.position.y-1;
        }
       SDL_Flip(ecran);
       break;
case SDLK_LEFT : 
  m.rect.x-=10;
c.position.x-=1;
   
 xx=detectCollPP (back2,m.rect) ;

 if(xx==1)
        {
         m.rect.x=m.rect.x-10;
         c.position.x=c.position.x-1;
        }
        

       
       
       SDL_BlitSurface(image, NULL, ecran, &posimage);

       afficher_minimap(m,c,ecran);
       
       SDL_Flip(ecran);
break;
case SDLK_RIGHT:
  m.rect.x+=10;
c.position.x+=1;
   
 xx=detectCollPP (back2,m.rect) ;

 if(xx==1)
        {
         m.rect.x=m.rect.x-10;
         c.position.x=c.position.x-1;
        }
        

       
       
       SDL_BlitSurface(image, NULL, ecran, &posimage);

       afficher_minimap(m,c,ecran);
       
       SDL_Flip(ecran);

     }   
   }
   xx=0;
   afficher_monguela(&t,ecran);
 }
   // temps();
 SDL_FreeSurface(ecran);
 SDL_Quit();
 return EXIT_SUCCESS;
}


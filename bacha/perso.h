#include <string.h>
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
  SDL_Surface *image[27] , *vie[3] ;
  SDL_Rect   pos ,posvie;

  int   direction ;
  int vitesse;
  int numIm;

  float vx,vy;
  int status;
}personnage;

personnage  initialiser_perso(personnage perso,char ch[]);
void afficher_perso(personnage perso, SDL_Surface *screen );
void deplacer_perso(SDL_Event *event,personnage *p,int *continuer);
void Gravite(personnage* perso,float factgravite,float factsautmaintenu,SDL_Event *event);
void ControleSol(personnage* perso);
void Saute(personnage* perso,float impulsion);

#include "main.h"


////////////////////////////////////////////////////////////////////////////////
int main()
{
  Uint32 timer,elapsed;
  personnage p;
  SDL_Surface *ecran,*fond;
  SDL_Rect pos;
  SDL_Event event;
  int bfin = 0;
  if (SDL_Init(SDL_INIT_VIDEO ) < 0)
	{
		fprintf(stderr, "Echec d'initialisation de SDL.\n");
		return 1;
	}
  printf("Bonjour le monde, SDL est initialis� avec succ�s.\n");

  ecran = SDL_SetVideoMode(400, 320, 32, SDL_HWSURFACE);

  if ( ecran == NULL )
	{
		fprintf(stderr, "Echec de changement du mode video : %s.\n", SDL_GetError());
		return 1;
	}
  char ch[100]="personnage/";
  fond = IMG_Load("lvl1.png");
  pos.x=0;
  pos.y=0;

  //bacha.position.x = 0;
  //bacha.position.y = 0;
  p=initialiser_perso(p,ch);
  SDL_EnableKeyRepeat(1,1);

  //////////////////////////////////////////////////////////////////////////////
  while (!bfin){
    timer = SDL_GetTicks();
    SDL_BlitSurface(fond, NULL, ecran, &pos);
    SDL_PollEvent(&event);
    deplacer_perso(&event,&p,&bfin);
    switch(event.type)
    {
      case SDL_QUIT:
        bfin = 1;
        break;
    }
    /*
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_c:
                p.vitesse = 20;
                break;
          case SDLK_UP:
            if (p.pos.y != 0){
              p.pos.y=p.pos.y-10;
            }

            break;
          case SDLK_RIGHT:
            p.direction=0;

            //bacha.position.x++;

            break;
          case SDLK_LEFT:
            p.direction=1;
            deplacer_perso(&event,&p,&bfin);
            //bacha.position.x--;
            break;
        }
        break;
        case SDL_KEYUP:
          switch(event.key.keysym.sym)
          {
            case SDLK_c:
                p.vitesse = 5;
                break;
            case SDLK_UP:

              if (p.pos.y != 80){
                p.pos.y=p.pos.y+80;
              }

            break;
            case SDLK_RIGHT:
              p.numIm =0;
              break;
            case SDLK_LEFT:
            p.numIm =13;
            break;




          }
          break;
    }*/

    afficher_perso(p,ecran);
    SDL_Flip(ecran);
    elapsed = SDL_GetTicks() - timer;
		if (elapsed<30)
			SDL_Delay(30-elapsed);
  }
  //SDL_FreeSurface(p.image);
  SDL_Quit();

  return 0;

}

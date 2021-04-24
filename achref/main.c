#include "background.h"


int main(int argc, char** argv)
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
screen=SDL_SetVideoMode (width,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("The secret Recipe", NULL);

background b;
Input I;
bool running=true;
SDL_Event event;
//music////////////////////////////////////////////////////////////////
Mix_Music *Intro = NULL;
	if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
		return 0;
	}
	Intro = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic( Intro, -1 );
//////////////////////////////////////////////////////////////////////

initialiser_backround (&b);
initialiser_input(&I);


while(running)
{


while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:
			running=false;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT :
				I.left=1;

      		break;
      		case SDLK_RIGHT :
				I.right=1;

      		break;
		case SDLK_UP :
				I.up=1;

      		break;
		case SDLK_DOWN :
				I.down=1;

      		break;
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
			break;
			case SDLK_LEFT :
				I.left=0;
      			break;
			case SDLK_UP :
				I.up=0;
      			break;
			case SDLK_DOWN :
				I.down=0;
      			break;
			}
		break;
		}
	}


	scrolling(&b,screen,I);
	afficher_background(screen,&b);
}
Mix_FreeMusic( Intro );
Mix_CloseAudio();	
SDL_FreeSurface(b.bg);
SDL_Quit();
return 0;
}

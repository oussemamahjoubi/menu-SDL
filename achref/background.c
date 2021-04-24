#include "background.h"

void initialiser_backround (background *b)
{
b->x_relative=0;
b->y_relative=0;
b->bg=NULL;

b->camera.x=0;
b->camera.y=height_bg-height;
b->camera.w=width;
b->camera.h=height;
b->bg=IMG_Load("background1.png");
}

void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->bg,&b->camera,screen,NULL);
SDL_Flip(screen);
}

void scrolling(background *b,SDL_Surface *screen,Input i)
{
	if (b->camera.x<width_bg-width&&i.right==1)
	{
		b->camera.x+=SPEED;
	}
	if (b->camera.x>0&&i.left==1)
	{
		b->camera.x-=SPEED;

	}
	if (b->camera.y<height_bg-height&&i.down==1)
	{
		b->camera.y+=SPEED;
	}
   	if (b->camera.y>0&&i.up==1)
	{
		b->camera.y-=SPEED;
	}
}

void initialiser_input (Input *I)
{
I->left=0;
I->right=0;
I->down=0;
I->up=0;
}

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#define SPEED 5
#define width 1000
#define height 450
#define width_bg 5000
#define height_bg 680

typedef struct Input
{
 int left,right,up,down;

} Input;

typedef struct background
{
int x_relative,y_relative;
SDL_Surface *bg;
SDL_Rect camera;
}background;

void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling (background *b,SDL_Surface *screen,Input i);
void initialiser_input (Input *I);


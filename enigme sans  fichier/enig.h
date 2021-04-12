#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct 
{
 SDL_Surface * srf;
 SDL_Rect pos;
}Imm;

void init_enigme(Imm * e) ;
void  load_enigme(Imm* screen  , char image [],Imm *e,int *alea) ;
 int solution_e (char image []) ;
int check_input_enigme(int * running,int *run);
void display_enigme(Imm* screen,int s,int r,Imm *en) ;

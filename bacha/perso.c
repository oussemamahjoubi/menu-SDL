#include "perso.h"

personnage initialiser_perso(personnage perso,char ch[100])
{
int i;
char ch1[100];
char n [3];
for(i=0;i<26;i++)
{
strcpy(ch1,"");
strcat (ch1,ch);
sprintf (n, "%d",i);
strcat (ch1,n);
strcat (ch1,".png");
 printf ("%s \n ",ch1);
perso.image[i]=IMG_Load(ch1);

 //ch[strlen(ch)-5]+=1;

if (perso.image[i]==NULL)
	{
	printf("Unable to load personnage %s\n" , IMG_GetError());
}
        perso.pos.w=(int)perso.image[i]->w;
perso.pos.h=(int)perso.image[i]->h;

}
perso.vie[0]=IMG_Load("vie/0.png");
perso.posvie.x=380-perso.vie[0]->w;
perso.posvie.y=10;
perso.numIm=0;
perso.direction=0;
perso.pos.x=150.0f;
perso.pos.y=150.0f;
perso.vitesse = 0;
perso.status = 0;
perso.vx = perso.vy = 0.0f;


return perso;

}

void afficher_perso(personnage perso, SDL_Surface *ecran )
{
     SDL_Surface *s=perso.image[perso.numIm];
SDL_BlitSurface (s,NULL,ecran,&perso.pos);
SDL_BlitSurface (perso.vie[0],NULL,ecran,&perso.posvie);
//SDL_Delay (50);
SDL_Flip (ecran);

}
void Saute(personnage* perso,float impulsion)
{
	perso->vy = -impulsion;
	perso->status = 1;
}
void ControleSol(personnage* perso)
{
	if (perso->pos.y>150.0f)
	{
		perso->pos.y = 150.0f;
		if (perso->vy>0)
			perso->vy = 0.0f;
		perso->status = 0;
	}
}
void Gravite(personnage* p,float factgravite,float factsautmaintenu,SDL_Event *event)
{
  switch(event->type)
      {
          case SDL_KEYDOWN:
              switch(event->key.keysym.sym)
          {
              case SDLK_SPACE:
                if (p->status == 1)factgravite/=factsautmaintenu;
                break;
              }}
              p->vy += factgravite;
              if ((p->direction == 0)&&(p->status==1)){
               p->numIm=2;
             }
             if ((p->direction == 1)&&(p->status==1)){
              p->numIm=15;
            }
}
void deplacer_perso(SDL_Event *event,personnage *p,int *fin)
{
  float lateralspeed = 0.5f;
	float airlateralspeedfacteur = 0.5f;
	float maxhspeed = 3.0f;
	float adherance = 1.5f;
	float impulsion = 6.0f;
	float factgravite = 0.5f;
	float factsautmaintenu = 3.0f;



   // SDL_PollEvent(event);
   if (p->status == 1) // (*2)
   lateralspeed*= airlateralspeedfacteur;
    switch(event->type)
    {
        case SDL_QUIT:
            (*fin)=0;
            break;
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {
          case SDLK_SPACE:
                if (p->status == 0){
                  p->vitesse = 0;
                Saute(p,impulsion);

                }
              break;
            case SDLK_c:
                  p->vitesse = 1;
                  p->vx=p->vx*30;
                  break;

            case SDLK_RIGHT:
                   /*if (perso->status == 1) // (*2)
                    lateralspeed*= airlateralspeedfacteur;*/

                   if (p->numIm>13) p->numIm=0;
                    p->numIm++;
                    p->numIm=p->numIm%13;
                p->direction=0;
                p->vx+=lateralspeed;
                //p->pos.x=p->pos.x+p->vitesse;

                break;
            case SDLK_LEFT:

                  if (p->numIm<13 ) p->numIm=4;
                    p->numIm++;
                    p->numIm=p->numIm%13+13;
                p->direction=1;
                //p->pos.x=p->pos.x-p->vitesse;
                p->vx-=lateralspeed;

                break;
        }
          break ;
        case SDL_KEYUP:
        switch(event->key.keysym.sym)
        {
          case SDLK_c:
              p->vx=p->vx/30;
              p->vitesse = 0;
              break;/*
          case SDLK_UP:

              if (p->pos.y != 80){
                p->pos.y=p->pos.y+80;
              }

              break;
              */
          case SDLK_RIGHT:
              p->numIm =0;
              p->vx=0;
              break;
          case SDLK_LEFT:
              p->numIm =13;
              p->vx=0;
              break;

          }
            break;


    }
    if (p->vitesse==0){
    if (p->vx>maxhspeed) // (*4)
		  p->vx = maxhspeed;
	  if (p->vx<-maxhspeed)
		  p->vx = -maxhspeed;
    }
      Gravite(p,factgravite,factsautmaintenu,event);
      ControleSol(p);
    p->pos.x +=p->vx;
	  p->pos.y +=p->vy;
}

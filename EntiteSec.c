#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"

image init_bg(char nomimage[100],int x,int y)
{
image bg;
bg.back=IMG_Load(nomimage);//load image
bg.positiond.x=x;//position x de bg
bg.positiond.y=y;//position y de bg
return bg;
}
void display_bg(SDL_Surface *ecran,image bg)
{
SDL_BlitSurface(bg.back,NULL,ecran,&bg.positiond);//afficher l image
//SDL_Flip(ecran);//refresh ecran
}



vtr init_vtr()
{
    vtr v;
    v.vtr[0]=IMG_Load("vtr3.png");
    v.positionvtr.x = 10;
    v.positionvtr.y = 1;
  return v;
}


robot init_perso()
{
    robot rob;
    rob.robot[0] = IMG_Load("perso0.png");
    rob.robot[1] = IMG_Load("perso1.png");
    rob.robot[2] = IMG_Load("perso2.png");
    rob.positionrobot.x = 0;
    rob.positionrobot.y = 0;
  return rob;
}




robot  move(int i,image bg,SDL_Surface *ecran,robot rob)
{
   
  rob.positionrobot.x+=10;

        if (rob.positionrobot.x>600) //lorsque x=600 retour a la position 0
         {
     rob.positionrobot.x=0;
         }
printf("pos pers %d\n",rob.positionrobot.x);
return rob;
}

void affichep(robot rob,SDL_Surface *ecran,int *i)
{

   ( *i)++;
printf("%d",*i);
        if (*i==3)
        {
            *i=0;
        }
       SDL_BlitSurface(rob.robot[*i],NULL,ecran,&rob.positionrobot);
}


void free_bg(image img)
{
	SDL_FreeSurface(img.back);//Liberer memoire
}

void free_pers(robot rob)
{
int i=0;
for(i=0;i<=3;i++)
     {
     //printf("\n");
     //printf("Free_Perso=>[%d] \n",i);
     SDL_FreeSurface(rob.robot[i]);
}

}


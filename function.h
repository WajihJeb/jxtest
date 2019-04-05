#ifndef FNC_H_
#define FNC_H_

typedef struct image
{
	SDL_Surface *back;//wyn chnachargo image
	SDL_Rect positiond;// Position mta3 background
}image;

typedef struct robot
{
	SDL_Surface *robot[3];//wyn chnachargo image
SDL_Rect positionrobot;
}robot;



typedef struct vtr
{
SDL_Surface *vtr[1];
SDL_Rect positionvtr;
}vtr;



//+++++++++++++++



image init_bg(char nomimage[100],int x,int y);
void display_bg(SDL_Surface *ecran,image img);
robot move(int i,image bg,SDL_Surface *ecran,robot rob);
void affichep(robot rob,SDL_Surface *ecran,int *i);
robot init_perso();
void free_pers(robot rob);
void free_bg(image img);

#include <SDL/SDL.h>
#include "defs.h"
#include "personne.h"
#include "background.h"
#include <stdio.h>

int loadPersonneImages(Personne * A)
{
	int i;
	char buf[50];
	char buf0[]="../images/personne";
	char bmp[]=".bmp";
	for(i=0; i<4; i++) {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		

		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}
	return(0);
}

void initPersonne(Personne *A)
{
	
	A->position.x=0;
	A->position.y=SCREEN_H - A->image[0]->h;
	A->position.w=A->image[0]->w;
	A->position.h=A->image[0]->h;
	A->acceleration=0;
	
	A->moving=0;
}

void movePersonne(Personne *A,Background *B)
{
		B->backgroundPos.x=B->backgroundPos.x+5; //dx=5
}

void freePersonne(Personne *A)
{
	int i;
	for(i=0; i<4; i++)
		SDL_FreeSurface(A->image[i]);
}

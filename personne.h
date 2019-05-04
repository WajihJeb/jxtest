#ifndef Voiture_H
#define Voiture_H
#include <SDL/SDL.h>
#include "background.h"

		

		
struct Personne{
	
SDL_Rect position;
	SDL_Surface * image[5];
	
	
	int direction; //0:right 1:left 2:up
	int moving; //0:not moving 1:moving
	float Mass;

	double velocity;
	double acceleration;

};
typedef struct Personne Personne;

int loadPersonneImages(Personne * A);

void initPersonne(Personne *A);

void movePersonne(Personne *A,Background *B);

void freePersonne(Personne *A);

#endif

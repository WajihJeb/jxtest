#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
#include "background.h"
#include "personne.h"
#include "jeu.h"


int jouer(SDL_Surface * screen)
{
	int done = 0;
	int i=0;
Uint32 tempactuel=0;
Uint32 dt=1;
	
	Personne per;
	Background Backg;
	
	
	SDL_Event event;
	int keysHeld[323] = {0}; // everything false
	
	

	if(loadPersonneImages(&per) == -1) {
		printf("Erreuer Chargement personnage Images\n");
		return(-1);

	}

	if(loadBackground(&Backg) == -1) {
		printf("Erreuer Chargement Background Images\n");
		return(-1);
	}
	

	initBackground(&Backg);
	initPersonne(&per);


	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {


		while (SDL_PollEvent(&event)) {

			switch (event.type) {
				
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				per.moving=1; //move
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				per.moving=0;
				
				break;

			}
			// exit if right is pressed
			
if (keysHeld[SDLK_ESCAPE]) //acceleration
				done = 1;
			if(keysHeld[SDLK_RIGHT]) {
				
per.acceleration+=0.05;
				per.direction=0; //right direction
Backg.backgroundPos.x+=per.velocity/dt+per.acceleration;

				i++;
			}

		} // end of message processing
		i=i%4;
		//Blit the bachground to the backbuffer
		blitBackground(&Backg,screen);

		//Blit personne to screen
		if(!per.moving)
			i=0;
		if(per.direction == 0)
			SDL_BlitSurface(per.image[i],NULL,screen,&per.position);
			


		SDL_Flip(screen);
		
	dt=SDL_GetTicks()-tempactuel;	
		
	}

	                // free loaded bitmap

	freePersonne(&per);
	freeBackground(&Backg);
	

    TTF_Quit();	
	return(0);
}

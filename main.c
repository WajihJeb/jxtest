#include "defs.h"
#include "jeu.h"
#include <SDL/SDL.h>


int main ()
{

	SDL_Surface *screen;
	

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "Unable to init SDL: %s\n", SDL_GetError() );
		return 1;
	}

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,
	                          SDL_HWSURFACE|SDL_DOUBLEBUF | SDL_SRCALPHA);

	jouer(screen);


	return 0;
}

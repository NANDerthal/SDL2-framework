#ifndef PARALLAX_H
#define PARALLAX_H

#include <SDL2/SDL.h>

#include "Background.h"
#include "Physics.h"

class Parallax: public Background {

private:
	double scrollSpeed; // fraction of camera scroll speed
	SDL_Rect position;

public:
	Parallax();
	void setPosition( SDL_Rect* newPoisiton );
	void setScrollSpeed( double newScrollSpeed );
	void move( const Velocity &velocity, int elapsedTime );
	void draw( SDL_Renderer* renderer, int animationID, int frame = -1 );

};

#endif

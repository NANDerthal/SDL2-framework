#ifndef PARALLAX_H
#define PARALLAX_H

#ifdef USING_WINDOWS
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#include "Background.h"
#include "Physics.h"
#include "utility.hpp"

class Parallax: public Background {

private:
	double scrollSpeed; // fraction of camera scroll speed
	SDL_Rect position;
	utility::Position actualPosition;

public:
	Parallax();
	void setPosition( SDL_Rect* newPoisiton );
	void setScrollSpeed( double newScrollSpeed );
	void move( const Velocity &velocity, int elapsedTime );
	void draw( SDL_Renderer* renderer, int animationID, int frame = -1 );

};

#endif

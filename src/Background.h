#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Animation.h"

class Background {

protected:
	Animation animation;
	bool initialized;

	SDL_Rect* getRendererSize( SDL_Renderer* renderer );

public:
	Background();
	void init( SDL_Renderer* renderer, const AnimationData &data );
	void draw( SDL_Renderer* renderer );
};

#endif

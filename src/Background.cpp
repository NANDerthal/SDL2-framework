#include "Background.h"

Background::Background() {
	initialized = false;
}

Background::~Background() {
	animation.~Animation();
}

void Background::init( SDL_Renderer* renderer, const AnimationData &data ) {
	animation.init( renderer, data );
	// TODO: sanity check animation dimensions against window
	initialized = true;
}

SDL_Rect* Background::getRendererSize( SDL_Renderer* renderer ) {
	int w, h;
	if ( SDL_GetRendererOutputSize( renderer, &w, &h ) < 0 ) {
		printf( "Renderer size could not be read! SDL_Error: %s\n", SDL_GetError() );	
		return nullptr;
	}

	SDL_Rect* output = new SDL_Rect;
	output->x = 0;
	output->y = 0;
	output->w = w;
	output->h = h;
	
	return output;
}	

void Background::draw( SDL_Renderer* renderer ) {
	if ( !initialized ) {
		printf( "Background was not initialized. Cannot draw!" );
		return;
	}	
	
	SDL_Rect* location = getRendererSize( renderer );

	animation.draw( renderer, location, location, 0 );

	delete location;
	location = nullptr;
}

#include <cmath>
#include "Parallax.h"

Parallax::Parallax() {
	position = {0,0,0,0};
	scrollSpeed = 0;
}

void Parallax::setPosition( SDL_Rect* newPosition ) {
	position = *newPosition;
}

void Parallax::setScrollSpeed( double newScrollSpeed ) {
	scrollSpeed = newScrollSpeed;
}

void Parallax::move( const Velocity &velocity, int elapsedTime ) {
	position.x += std::floor( velocity.x * scrollSpeed * elapsedTime );
	position.y += std::floor( velocity.y * scrollSpeed * elapsedTime );
}

void Parallax::draw( SDL_Renderer* renderer, int animationID, int frame ) {
	if ( !initialized ) {
		printf( "Parallax element was not initialized. Cannot draw!" );
		return;
	}

	SDL_Rect* location = getRendererSize( renderer );

	animation.draw( renderer, location, &position, animationID, frame );

	delete location;
	location = nullptr;
}

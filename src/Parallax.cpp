#include "Parallax.h"
#include "utility.hpp"

Parallax::Parallax() {
	scrollSpeed = 0;
	position = {0,0,0,0};
	actualPosition = {0,0};
}

void Parallax::setPosition( SDL_Rect* newPosition ) {
	position = *newPosition;
	actualPosition.x = position.x;
	actualPosition.y = position.y;
}

void Parallax::setScrollSpeed( double newScrollSpeed ) {
	scrollSpeed = newScrollSpeed;
}

void Parallax::move( const Velocity &velocity, int elapsedTime ) {
	actualPosition.x -= velocity.x * scrollSpeed * elapsedTime;
	actualPosition.y -= velocity.y * scrollSpeed * elapsedTime;
	position.x = utility::roundNotZero( actualPosition.x );
	position.y = utility::roundNotZero( actualPosition.y );
}

void Parallax::draw( SDL_Renderer* renderer, int animationID, int frame ) {
	if ( !initialized ) {
		printf( "Parallax element was not initialized. Cannot draw!" );
		return;
	}

	SDL_Rect* location = getRendererSize( renderer );

	animation.draw( renderer, &position, location, animationID, frame );

	delete location;
	location = nullptr;
}

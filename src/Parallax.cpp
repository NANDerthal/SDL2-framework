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
	actualPosition.x += velocity.x * scrollSpeed * elapsedTime;
	actualPosition.y += velocity.y * scrollSpeed * elapsedTime;
	position.x = utility::roundNotZero( actualPosition.x );
	position.y = utility::roundNotZero( actualPosition.y );
}

void Parallax::draw( SDL_Renderer* renderer, int animationID, int frame ) {
	if ( !initialized ) {
		printf( "Parallax element was not initialized. Cannot draw!" );
		return;
	}

	SDL_Rect* renderLocation = getRendererSize( renderer );
	SDL_Rect spritePosition = position;
	
	// check if we are outside the sprite boundaries
	int posEdgeX = ( spritePosition.x + spritePosition.w ) - animation.getFrameWidth();
	int posEdgeY = ( spritePosition.y + spritePosition.h ) - animation.getFrameHeight();
	
	if ( spritePosition.x < 0 ) {
		renderLocation->x -= spritePosition.x;
		spritePosition.x = 0;
	} else if ( posEdgeX > 0 ) {
		renderLocation->x -= posEdgeX;
		spritePosition.x = animation.getFrameWidth() - spritePosition.w;
	}
	
	if ( spritePosition.y < 0 ) {
		renderLocation->y -= spritePosition.y;
		spritePosition.y = 0;
	} else if ( posEdgeY > 0 ) {
		renderLocation->y -= posEdgeY;
		spritePosition.y = animation.getFrameHeight() - spritePosition.h;
	}

	animation.draw( renderer, renderLocation, &spritePosition, animationID, frame );

	delete renderLocation;
	renderLocation = nullptr;
}

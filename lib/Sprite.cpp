#include "Sprite.h"

Sprite::Sprite() {
	texture = NULL;
	width = 0;
	height = 0;
}

Sprite::~Sprite() {
	freeTexture();
}

int Sprite::getWidth() const {
	return width;
}

int Sprite::getHeight() const {
	return height;
}

bool Sprite::init( SDL_Renderer* renderer, std::string filename ) {
	freeTexture();
	
	// load image to surface
	const char* path = filename.c_str();
	SDL_Surface* surface = IMG_Load( path );
	if ( surface == NULL ) {
		printf( "Unable to create surface from %s! SDL Error: %s\n", path, SDL_GetError() );
		return false;
	}
	
	// create texture
	texture = SDL_CreateTextureFromSurface( renderer, surface );
	if ( texture == NULL ) {
		printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		return false;
	}

	width = surface->w;
	height = surface->h;

	SDL_FreeSurface( surface );
	
	// Initialization was successful
	return true;
}

void Sprite::draw( SDL_Renderer* renderer, SDL_Rect* frame, SDL_Rect* location ) const {
	int err = SDL_RenderCopy( renderer, texture, frame, location );
	if ( err ) {
		printf("Error rendering sprite! SDL Error: %s\n", SDL_GetError() );
	}
}

void Sprite::freeTexture() {
	if ( texture != NULL ) {
		SDL_DestroyTexture( texture );
		texture = NULL;
		width = 0;
		height = 0;
	}
}


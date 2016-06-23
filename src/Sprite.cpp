#include "Sprite.h"

Sprite::Sprite() {
	texture = NULL;
	width = 0;
	height = 0;
}

Sprite::~Sprite() {
	freeTexture();
}

bool Sprite::init( SDL_Renderer* renderer, std::string filename ) {
	freeTexture();
	const char* path = filename.c_str();
	SDL_Surface* surface = IMG_Load( path );
	if( surface == NULL ) {
		printf( "Unable to create surface from %s! SDL Error: %s\n", path, SDL_GetError() );
		return false;
	}

	texture = SDL_CreateTextureFromSurface( renderer, surface );
	if( texture == NULL ) {
		printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		return false;
	}

	width = surface->w;
	height = surface->h;

	SDL_FreeSurface( surface );

	return true;
}

void Sprite::freeTexture() {
	if( texture != NULL ) {
		SDL_DestroyTexture( texture );
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void Sprite::draw( SDL_Renderer* renderer, SDL_Rect* location, SDL_Rect* frame ) {
	SDL_RenderCopy( renderer, texture, frame, location );
}	

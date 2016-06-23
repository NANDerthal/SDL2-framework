#include "Game.h"

Game::Game() {

}

Game::~Game() {
	SDL_Quit();
}

bool Game::init() {
	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	
	// Initialization was successful
	return true;
}


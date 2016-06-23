#include "Game.h"

Game::Game() {
}

Game::~Game() {
	IMG_Quit();
	SDL_Quit();
}

Window Game::newWindow( std::string winTitle, int height, int width ) {
	Window win;
	win.init( winTitle, height, width);

	return win;
}

void Game::loadMenu() {
	// TODO: IMPLEMENT 
}

void Game::loadLevel( std::string saveFile ) {
}

bool Game::init() {
	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	// Initialize SDL_Image with PNG support
	int imgFlags = IMG_INIT_PNG;
	if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return false;
	}
	
	// Create window
	mainWindow = newWindow();

	// Load Menu level
	loadMenu();

	// Initialization was successful
	return true;
}

#include "Window.h"

Window::Window( int height, int width ) {
	window = NULL;
	renderer = NULL;
	screenHeight = height;
	screenWidth = width;
}

Window::~Window() {
	SDL_DestroyRenderer( renderer );
	renderer = NULL;
	
	SDL_DestroyWindow( window );
	window = NULL;
	
	SDL_Quit();
}

int Window::getWidth() {
	return screenWidth;
}

int Window::getHeight() {
	return screenHeight;
}

SDL_Renderer* Window::getRenderer() {
	return renderer;
}

bool Window::init( std::string winTitle ) {
	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}	
	
	// Initialize window
	window = SDL_CreateWindow( winTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, 
								SDL_WINDOWPOS_UNDEFINED, screenWidth, 
								screenHeight, SDL_WINDOW_SHOWN );
	if ( window == NULL ) {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	
	// Initialize renderer
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	
	// Initialization was successful
	return true;
}

void Window::resizeWindow( int newWidth, int newHeight ) {
	screenWidth = newWidth;
	screenHeight = newHeight;
	
	if ( window != NULL ) {
		SDL_SetWindowSize( window, screenWidth, screenHeight );
	}
}

void Window::render( ) {
	SDL_RenderPresent( renderer );
}


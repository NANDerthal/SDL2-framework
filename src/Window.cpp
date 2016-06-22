#include "Window.h"

Window::Window( int height, int width ) {
	window = nullptr;
	screenHeight = height;
	screenWidth = width;
}

Window::~Window() {
	SDL_DestroyWindow( window );
	window = nullptr;
	
	SDL_Quit();
}

void Window::resizeWindow( int newWidth, int newHeight ) {
	screenWidth = newWidth;
	screenHeight = newHeight;
	
	if ( window != nullptr ) {
		SDL_SetWindowSize( window, screenWidth, screenHeight );
	}
}

int Window::getWidth() {
	return screenWidth;
}

int Window::getHeight() {
	return screenHeight;
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
	
	// Initialization was successful
	return true;
}

void Window::render( SDL_Renderer* renderer ) {
	SDL_RenderPresent( renderer );
}


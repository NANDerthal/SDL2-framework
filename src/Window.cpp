#include "Window.h"
#include <SDL.h>
#include <string>

Window::Window( int height = 480, int width = 640 ) {
	window = NULL;
	screenHeight = height;
	screenWidth = width;
}

Window::~Window() {
	SDL_DestroyWindow( window );
	window = NULL;
}

bool Window::init( std::string winTitle ) {
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	
	window = SDL_CreateWindow( winTitle, SDL_WINDOWPOS_UNDEFINED, 
								SDL_WINDOWPOS_UNDEFINED, screenWidth, 
								screenHeight, SDL_WINDOW_SHOWN );
	
	if ( gWINDOW == NULL ) {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	
	return true;
}

void Window::resizeWindow( int newWidth, int newHeight ) {
	screenWidth = newWidth;
	screenHeight = newHeight;
	SDL_SetWindowSize( window, screenWidth, screenHeight );
}

int Window::getWidth() {
	return screenWidth;
}

int Window::getHeight() {
	return screenHeight;
}

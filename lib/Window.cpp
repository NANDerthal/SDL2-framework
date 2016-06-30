#include "Window.h"

Window::Window( int height, int width ) {
	window = NULL;
	renderer = NULL;
	screenHeight = height;
	screenWidth = width;
}

void Window::copyWindow( const Window &source ) {
	if ( source.getRenderer() == NULL ) {
		window = NULL;
		renderer = NULL;
		screenHeight = source.getHeight();
		screenWidth = source.getWidth();
	}
	else {
		const char* title = source.getTitle();
		init( title, source.getHeight(), source.getWidth() );
	}
}

Window::Window( const Window &source ) {
	copyWindow( source );
}

Window& Window::operator= ( const Window &source ) {
	copyWindow( source );
	return *this;
}

Window::~Window() {
	SDL_DestroyRenderer( renderer );
	renderer = NULL;
	
	SDL_DestroyWindow( window );
	window = NULL;
}

int Window::getWidth() const {
	return screenWidth;
}

int Window::getHeight() const {
	return screenHeight;
}

SDL_Renderer* Window::getRenderer() const {
	if ( window == NULL ) {
		return NULL;
	}
	else {
		return renderer;
	}
}

const char* Window::getTitle() const {
	if ( window == NULL ) {
		return "";
	}
	else {
		return SDL_GetWindowTitle( window );
	}
}

bool Window::init( std::string winTitle, int height, int width ) {
	screenHeight = height;
	screenWidth = width;	
	
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

void Window::render( ) const {
	SDL_RenderPresent( renderer );
}


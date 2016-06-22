#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window {
		
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int screenHeight;
	int screenWidth;

public:
	Window( int height = 480, int width = 640 );
	~Window();
	
	// Read member variables
	int getWidth();
	int getHeight();
	SDL_Renderer* getRenderer();
	
	// Set member variables and adjust window accordingly
	void resizeWindow( int newWidth, int newHeight );
	
	// Initialize SDL, window, and renderer
	// Returns true if successful, false if failed
	bool init( std::string winTitle );
	
	// Draw to window whatever was in renderer
	void render( );
};

#endif

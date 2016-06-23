#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <SDL2/SDL.h>

class Window {
		
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int screenHeight;
	int screenWidth;
	
	void copyWindow( const Window &source );

public:
	Window( int height = 480, int width = 640 );
	Window( const Window &source );
	Window& operator= ( const Window &source );
	~Window();
	
	// Read member variables
	int getWidth() const;
	int getHeight() const;
	SDL_Renderer* getRenderer() const;
	const char* getTitle() const;
	
	// Initialize window and renderer
	// Returns true if successful, false if failed
	bool init( std::string winTitle, int height = 480, int width = 640 );
	
	// Set member variables and adjust window accordingly
	void resizeWindow( int newWidth, int newHeight );
	
	// Draw to window whatever was in renderer
	void render( ) const;
};

#endif


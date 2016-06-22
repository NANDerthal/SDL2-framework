#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window {
		
private:
	SDL_Window* window;
	int screenHeight;
	int screenWidth;

public:
	Window( int height = 480, int width = 640 );
	~Window();

	bool init( std::string winTitle );
	void resizeWindow( int newWidth, int newHeight );
	int getWidth();
	int getHeight();

};

#endif

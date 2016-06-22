#ifndef Window
#define Window

class Window {

private:
	SDL_Window window;
	int screenHeight;
	int screenWidth;

public:
	
	Window( int height = 480, int width = 640 )
	
	~Window()

	void resizeWindow( int newWidth, int newHeight )
	int getWidth()
	int getHeight()
}

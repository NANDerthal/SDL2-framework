#ifndef INPUT_H
#define INPUT_H

#include <string>

#ifdef USING_WINDOWS
	#include <SDL.h>
	#include <SDL_ttf.h>
#else
	#include <SDL2/SDL.h>
	#include <SDL/SDL_ttf.h>
#endif

enum InputMode { MENU, PLATFORM, CODE };

class Input {

private:
	InputMode currentMode;
	SDL_Event* eventHandler;

public:
	Input();
	void changeMode( InputMode newMode );
	void getEvent( std::string );
	

};

#endif

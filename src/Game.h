#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "Window.h"

class Game {

private:
	Window mainWindow;

public:
	Game();
	~Game();
	
	// initialize SDL
	bool init();

};

#endif


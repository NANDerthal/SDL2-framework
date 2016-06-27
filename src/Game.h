#ifndef GAME_H
#define GAME_H

#include <string>

#ifdef USING_WINDOWS
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#include "SaveFile.h"
#include "Window.h"

class Game {

private:
	Window mainWindow;
	SaveFile save;

	Window newWindow( std::string winTitle, int height = 480, int width = 640 );
	void loadLevel( std::string saveFile = "" );

public:
	Game();
	~Game();
	
	// initialize SDL
	bool init();

};

#endif


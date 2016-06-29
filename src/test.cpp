#ifdef USING_WINDOWS
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#include "Animation.h"
#include "Background.h"
#include "Parallax.h"
#include "Sprite.h"
#include "utility.hpp"
#include "Window.h"

/* Sandbox testing environment
 *  
 */
 
 /*
 * If 'main' is defined we clear that definition
 * to get our default 'main' function back.
 * This is necessary for Windows with mingw.
 */
#ifdef main
# undef main
#endif /* main */

int main( int argc, const char* argv[] ) {
	// Init sdl without error handling 
	SDL_Init( SDL_INIT_VIDEO );
	IMG_Init( IMG_INIT_PNG );

	// Test window
	Window* window = new Window;
	window->init( "Fringe - Test" ); 

	SDL_Renderer* renderer = window->getRenderer();
	
	// Grab spritesheet
	AnimationData udlrDat = {
		"../testbox/udlr/udlr-sheet.png", // filename
		{ 0, 0 }, // delays
		{ 1, 4 }, // numframes
		100, // frameWidth
		100, // frameHeight
		2 // numAnimations
	};

	AnimationData guyDat = {
		"../testbox/img/bro.png", // filename
		{ 0, 4 }, // delays
		{ 1, 4 }, // numframes
		50, // frameWidth
		80, // frameHeight
		2 // numAnimations
	};

	AnimationData bgDat = {
		"../testbox/img/bg.png", // filename
		{ 0 }, // delays
		{ 1 }, // numframes
		640, // frameWidth
		480, // frameHeight
		1 // numAnimations
	};

	AnimationData hillDat = {
		"../testbox/img/hill.png", // filename
		{ 0 }, // delays
		{ 1 }, // numframes
		640, // frameWidth
		480, // frameHeight
		1 // numAnimations
	};
	
	AnimationData grassDat = {
		"../testbox/img/grass.png", // filename
		{ 0 }, // delays
		{ 1 }, // numframes
		1280, // frameWidth
		480, // frameHeight
		1 // numAnimations
	};
	
	// Test sprite
	Sprite* sprite = new Sprite;
	sprite->init( renderer, guyDat.filename );
	SDL_Rect spriteFrame = {0,0,guyDat.frameWidth,guyDat.frameHeight};
	SDL_Rect spritePos = {0,355,guyDat.frameWidth,guyDat.frameHeight};
	
	// Test animation
	enum Presses { UP, RIGHT, DOWN, LEFT };
	SDL_Rect loc = { 0, 0, 100, 100 };
	SDL_Rect src = { 0, 0, 100, 100 };
	Animation* anim = new Animation;
	anim->init( renderer, udlrDat );

	Animation* guy = new Animation;
	guy->init( renderer, guyDat);
	SDL_Rect guyFrameRect = spriteFrame;
	SDL_Rect guyPos = spritePos;
	utility::Position guyPosActual = { guyPos.x, guyPos.y };
	
	// Test background
	Background* bg = new Background;
	bg->init( renderer, bgDat );

	// Test Parallax
	Parallax* hill = new Parallax;
	hill->init( renderer, hillDat );
	SDL_Rect pos = {0,0,640,480};
	hill->setPosition( &pos );
	hill->setScrollSpeed( 0.42 );
	
	Parallax* grass = new Parallax;
	grass->init( renderer, grassDat );
	SDL_Rect grassPos = {0,0,640,480};
	grass->setPosition( &grassPos );
	grass->setScrollSpeed( 1.0 );

	bool quit = false;
	SDL_Event e;
	int moveDelay = 1;
	int drawDelay = 20;

	while ( !quit ) {
		// Event handling
		
		int press = -1;
		int animID = 0;
		int guyID = 0;
		
		while ( SDL_PollEvent( &e ) != 0 ) {
			if ( e.type == SDL_QUIT ) {
				quit = true;
			} else if ( e.type == SDL_KEYDOWN ) {
				// select surfaces based on key press
				switch ( e.key.keysym.sym ) {
					
					case SDLK_UP:
					press = UP;
					animID = 1;
					guyID = 1;
					break;
					
					case SDLK_DOWN:
					press = DOWN;
					animID = 1;
					guyID = 1;
					break;
					
					case SDLK_LEFT:
					press = LEFT;
					animID = 1;
					guyID = 1;
					break;
					
					case SDLK_RIGHT:
					press = RIGHT;
					animID = 1;
					guyID = 1;
					break;
					
					default:
					press = 0;
					animID = 0;
					guyID = 0;
					break;
					
				}
			}
		}
		
		const Uint8* keystate = SDL_GetKeyboardState( NULL );
		
		//continuous-response keys
		if ( keystate[SDL_SCANCODE_UP] ) {
			press = UP;
			animID = 1;
			guyID = 1;
		} else if ( keystate[SDL_SCANCODE_DOWN] ) {
			press = DOWN;
			animID = 1;
			guyID = 1;
		} else if ( keystate[SDL_SCANCODE_LEFT] ) {
			press = LEFT;
			animID = 1;
			guyID = 1;
		} else if ( keystate[SDL_SCANCODE_RIGHT] ) {
			press = RIGHT;
			animID = 1;
			guyID = 1;
		}
		
		
		// Logic
		
		Velocity vel = {0,0};
		switch ( press ) {
			// note that the origin is in the top left!
			case UP:
			vel.y = -1;
			break;

			case DOWN:
			vel.y = 1;
			break;

			case LEFT:
			vel.x = -1;
			break;
			
			case RIGHT:
			vel.x = 1;
			break;
			
			default:
			break;
		}

		hill->move( vel, moveDelay );
		grass->move( vel, moveDelay );
		guyPosActual.x += moveDelay*vel.x;
		guyPosActual.y += moveDelay*vel.y;
		guyPos.x = utility::roundNotZero( guyPosActual.x );
		guyPos.y = utility::roundNotZero( guyPosActual.y );
		
		// Drawing

		SDL_Delay( drawDelay );

		SDL_RenderClear( renderer );

		bg->draw( renderer );
		hill->draw( renderer, 0 );
		grass->draw( renderer, 0 );
		//sprite->draw( renderer, &spriteFrame, &spritePos );
		anim->draw( renderer, &loc, &src, animID, press  );
		guy->draw( renderer, &guyPos, &guyFrameRect, guyID );
		
		window->render();
	}

	delete sprite; //sprite->~Sprite();
	sprite = nullptr;
	delete anim; //anim->~Animation();
	anim = nullptr;
	delete guy; //guy->~Animation();
	guy = nullptr;
	delete bg; //bg->~Background();
	bg = nullptr;
	delete hill; //hill->~Parallax();
	hill = nullptr;
	delete grass; //grass->~Parallax();
	grass = nullptr;
	
	delete window; //window->~Window();
	window = nullptr;
	
	IMG_Quit();
	SDL_Quit();

	return 0;
}

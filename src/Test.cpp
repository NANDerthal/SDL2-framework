#include <SDL2/SDL.h>

#include "Animation.h"
#include "Background.h"
#include "Parallax.h"
#include "Sprite.h"
#include "utility.hpp"
#include "Window.h"

/* Sandbox testing environment
 *  
 */

int main( int argc, const char* argv[] ) {
	// Init sdl without error handling 
	SDL_Init( SDL_INIT_VIDEO );
	IMG_Init( IMG_INIT_PNG );

	// Test window
	Window window;
	window.init( "Fringe - Test" ); 

	SDL_Renderer* renderer = window.getRenderer();
	
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

	AnimationData hdDat = {
		"../testbox/img/hotdog.png", // filename
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
		269, // frameHeight
		1 // numAnimations
	};
	
	// Test sprite
	Sprite sprite;
	sprite.init( renderer, guyDat.filename );
	SDL_Rect spriteFrame = {0,0,guyDat.frameWidth,guyDat.frameHeight};
	SDL_Rect spritePos = {0,355,guyDat.frameWidth,guyDat.frameHeight};
	
	// Test animation
	enum Presses { UP, RIGHT, DOWN, LEFT };
	SDL_Rect loc = { 0, 0, 100, 100 };
	SDL_Rect src = { 0, 0, 100, 100 };
	Animation anim;
	anim.init( renderer, udlrDat );

	Animation guy;
	guy.init( renderer, guyDat);
	SDL_Rect guyFrameRect = spriteFrame;
	SDL_Rect guyPos = spritePos;
	utility::Position guyPosActual = { guyPos.x, guyPos.y };
	
	// Test background
	Background bg;
	bg.init( renderer, bgDat );

	// Test Parallax
	Parallax hill;
	hill.init( renderer, hillDat );
	SDL_Rect pos = {0,211,640,269};
	//SDL_Rect pos = {0,0,100,100};
	hill.setPosition( &pos );
	hill.setScrollSpeed( 0.42 );

	bool quit = false;
	SDL_Event e;
	int moveDelay = 1;
	int drawDelay = 50;

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

		hill.move( vel, moveDelay );
		guyPosActual.x += moveDelay*vel.x;
		guyPosActual.y += moveDelay*vel.y;
		guyPos.x = utility::roundNotZero( guyPosActual.x );
		guyPos.y = utility::roundNotZero( guyPosActual.y );
		
		// Drawing

		SDL_Delay( drawDelay );

		SDL_RenderClear( renderer );

		bg.draw( renderer );
		hill.draw( renderer, 0 );
		//sprite.draw( renderer, &spriteFrame, &spritePos );
		anim.draw( renderer, &loc, &src, animID, press  );
		guy.draw( renderer, &guyPos, &guyFrameRect, guyID );
		
		window.render();
	}

	IMG_Quit();
	SDL_Quit();

	return 0;
}

#include "Animation.h"
#include "Background.h"
#include "Parallax.h"
#include "Sprite.h"
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
		"img/lilboy.png", // filename
		{ 0 }, // delays
		{ 1 }, // numframes
		88, // frameWidth
		125, // frameHeight
		1 // numAnimations
	};

	AnimationData bgDat = {
		"img/bg.png", // filename
		{ 0 }, // delays
		{ 1 }, // numframes
		640, // frameWidth
		480, // frameHeight
		1 // numAnimations
	};

	AnimationData hdDat = {
		"img/hotdog.png", // filename
		{ 0 }, // delays
		{ 1 }, // numframes
		640, // frameWidth
		480, // frameHeight
		1 // numAnimations
	};

	AnimationData hillDat = {
		"img/hill.png", // filename
		{ 0 }, // delays
		{ 1 }, // numframes
		640, // frameWidth
		269, // frameHeight
		1 // numAnimations
	};
	
	// Test sprite
	Sprite sprite;
	sprite.init( renderer, udlrDat.filename );

	SDL_Rect r = {0,0,32,64};
	SDL_Rect f = {0,0,32,64};
	
	// Test animation
	enum Presses { UP, RIGHT, DOWN, LEFT };
	SDL_Rect loc = {0,64,100,100};
	SDL_Rect src = {0, 0, 100, 100};
	Animation anim;
	anim.init( renderer, udlrDat );

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
	int delay = 100;

	while ( !quit ) {
		// Event handling
		
		int press = -1;
		int animID = 0;
		
		while ( SDL_PollEvent( &e ) != 0 ) {
			if ( e.type == SDL_QUIT ) {
				quit = true;
			} else if ( e.type == SDL_KEYDOWN ) {
				// select surfaces based on key press
				switch ( e.key.keysym.sym ) {
					
					case SDLK_UP:
					press = UP;
					animID = 1;
					break;
					
					case SDLK_DOWN:
					press = DOWN;
					animID = 1;
					break;
					
					case SDLK_LEFT:
					press = LEFT;
					animID = 1;
					break;
					
					case SDLK_RIGHT:
					press = RIGHT;
					animID = 1;
					break;
					
					default:
					press = 0;
					animID = 0;
					break;
					
				}
			}
		}


		// Logic
		Velocity vel = {0,0};
		switch ( press ) {
			case UP:
			vel.y = 1;
			break;

			case DOWN:
			vel.y = -1;
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

		hill.move( vel, 10 );

		// Drawing

		SDL_Delay( delay );

		r.x++;

		bg.draw( renderer );
		hill.draw( renderer, 0 );


		sprite.draw( renderer, &f, &r );
		anim.draw( renderer, &loc, &src, animID, press  );
		window.render();
	}

	IMG_Quit();
	SDL_Quit();

	return 0;
}

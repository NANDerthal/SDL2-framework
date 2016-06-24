#include "Animation.h"
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
	
	// Test sprite
	Sprite sprite;
	sprite.init( renderer, udlrDat.filename );

	SDL_Rect r = {0,0,32,64};
	SDL_Rect f = {0,0,32,64};
	SDL_Rect bg = {0,0,640,480};
	
	// Test animation
	enum Presses { UP, RIGHT, DOWN, LEFT };
	SDL_Rect loc = {0,64,100,100};
	SDL_Rect src = {0, 0, 100, 100};
	Animation anim;
	anim.init( renderer, udlrDat );
	
	bool quit = false;
	SDL_Event e;

	while ( !quit ) {
		int press = 0;
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

		SDL_Delay( 100 );

		r.x++;
		
		SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderFillRect( renderer, &bg );	
		sprite.draw( renderer, &f, &r );
		anim.draw( renderer, &loc, &src, animID, press  );
		window.render();
	}

	IMG_Quit();
	SDL_Quit();

	return 0;
}

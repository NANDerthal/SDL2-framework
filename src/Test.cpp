#include "Sprite.h"
#include "Window.h"

/* Sandbox testing environment
 *  
 */

int main( int argc, const char* argv[] ) {
	// Init sdl without error handling 
	SDL_Init( SDL_INIT_VIDEO );
	IMG_Init( IMG_INIT_PNG );

	Window window;
	window.init( "Fringe - Test" ); 

	SDL_Renderer* renderer = window.getRenderer();

	std::string path = "img/lilguy.png";
	
	Sprite sprite;
	sprite.init( renderer, path );

	SDL_Rect r = {0,0,32,64};
	SDL_Rect f = {0,0,32,64};
	SDL_Rect bg = {0,0,640,480};
	bool quit = false;
	SDL_Event e;

	while ( !quit ) {
		while ( SDL_PollEvent( &e ) != 0 ) {
			if ( e.type == SDL_QUIT ) {
				quit = true;
			}
		}

		SDL_Delay( 100 );

		r.x++;
		
		SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderFillRect( renderer, &bg );	
		sprite.draw( renderer, &f, &r );
		window.render();
	}

	IMG_Quit();
	SDL_Quit();

	return 0;
}

#include "Game.h"

/*
 * If 'main' is defined we clear that definition
 * to get our default 'main' function back.
 * This is necessary for Windows with mingw.
 */
#ifdef main
# undef main
#endif /* main */

int main( int argc, const char* argv[] ) {
	Game newGame;
	return 0;
}

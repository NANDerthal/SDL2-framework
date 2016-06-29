#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#ifdef USING_WINDOWS
	#include <SDL.h>
	#include <SDL_image.h>
#else
	#include <SDL2/SDL.h>
	#include <SDL/SDL_image.h>
#endif

class Sprite {

private:
	SDL_Texture *texture;
	int width, height;

	// Sprites should not be copied for efficiency purposes
	Sprite( const Sprite &source ) = delete;
	Sprite& operator= ( const Sprite &source ) = delete;

public:
	Sprite();
	~Sprite();
	
	// Read member variables
	int getWidth() const;
	int getHeight() const;
	std::string getFilename() const;
	
	// Load texture and get dimensions
	bool init( SDL_Renderer* renderer, std::string filename );
	
	// draw frame of sprite at location in renderer
	void draw( SDL_Renderer* renderer, SDL_Rect* frame, SDL_Rect* location ) const;
	
	// clear texture
	void freeTexture();

};

#endif

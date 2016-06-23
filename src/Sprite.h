#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

class Sprite {

private:
	SDL_Texture *texture;
	int width, height;

public:
	Sprite();
	~Sprite();
	
	// Read member variables
	int getWidth();
	int getHeight();
	
	// Load texture and get dimensions
	bool init( SDL_Renderer* renderer, std::string filename );
	
	// draw frame of sprite at location in renderer
	void draw( SDL_Renderer* renderer, SDL_Rect* frame, SDL_Rect* location );
	
	// clear texture
	void freeTexture();

};

#endif

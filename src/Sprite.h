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

	bool init( SDL_Renderer* renderer, std::string filename );
	void draw( SDL_Renderer* renderer, SDL_Rect* location, SDL_Rect* frame );
	void freeTexture();

};

#endif

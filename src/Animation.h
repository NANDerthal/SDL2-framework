#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <string>

#include <SDL2/SDL.h>

#include "Sprite.h"

enum CharacterAnimations { WALK, RUN, JUMP };

struct AnimationData {
	std::string filename;
	std::vector< int > delays;
	std::vector< int > numFrames;
	int frameWidth, frameHeight, numAnimations;
};

class Animation {

private:
	Sprite sprite;
	std::vector< std::vector <SDL_Rect> > frames;
	std::vector< int > delays;
	std::vector< int > numFrames;
	int frameWidth, frameHeight;
	int currAnimation, currFrame;

public:
	Animation();
	
	// Read member variables
	int getWidth() const;
	int getHeight() const;
	int getDelay() const; // Delay is in ms
	int getNumFrames() const;
	int getFrameWidth() const;
	int getFrameHeight() const;
	int getCurrAnimation() const;
	int getCurrframe() const;
	
	// Load sprite and fill member variables
	void init( SDL_Renderer* renderer, const AnimationData &data );
	
	// Get frame of animation animationID
	void draw( SDL_Renderer* renderer, SDL_Rect* location, int animationID );

};

#endif

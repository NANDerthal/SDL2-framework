#include "Animation.h"

Animation::Animation() {
	frameWidth = 0;
	frameHeight = 0;
	currAnimation = 0;
	currFrame = 0;
}

// Read member variables

int Animation::getWidth() const {
	return sprite.getWidth();
}

int Animation::getHeight() const {
	return sprite.getHeight();
}

int Animation::getDelay() const {
	return delays[ currAnimation ];
}

int Animation::getNumFrames() const {
	return numFrames[ currAnimation ];
}

int Animation::getFrameWidth() const {
	return frameWidth;
}

int Animation::getFrameHeight() const {
	return frameHeight;
}

int Animation::getCurrAnimation() const {
	return currAnimation;
}

int Animation::getCurrframe() const {
	return currFrame;
}

// Load sprite and fill member variables
void Animation::init( SDL_Renderer* renderer, const AnimationData &data ) {
	sprite.init( renderer, data.filename );
	delays = data.delays;
	numFrames = data.numFrames;
	frameWidth = data.frameWidth;
	frameHeight = data.frameHeight;
	
	// calculate frame rectangle locations
	for ( int i = 0; i < data.numAnimations ; ++i ) {
		frames.push_back( animRow );
		for ( int j = 0; j < data.numFrames[ i ] ; ++j ) {
			SDL_Rect currFrame = { j*frameWidth, i*frameHeight,
									frameWidth, frameHeight };
			frames[i].push_back( currFrame );
		}
	}
}

// Get frame of animation animationID
void Animation::draw( SDL_Renderer* renderer, SDL_Rect* location, int animationID, int frame ) {
	// calculate which frame to get
	if ( animationID != currAnimation ) {
		currAnimation = animationID;
		if ( frame == -1 ) {
			currFrame = 0;
		} else {
			currFrame = frame;
		}
	} else {
		if ( frame = -1 ) {
			currFrame = frame;
		} else if ( ++currFrame == numFrames[ currAnimation ] ) {
			currFrame = 0;
		}
	}
	
	sprite.draw( renderer, &frames[ currAnimation ][ currFrame ], location );
}


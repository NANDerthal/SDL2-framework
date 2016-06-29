#ifndef CAMERA_H
#define CAMERA_H

#include "utility.hpp"

class Camera {
private:
	utility::Position position, displacement;
	int width, height, levelWidth, levelHeight;

	utility::Position getValidPosition( const utility::Position& center );

public:
	Camera();

	utility::Position getPosition();
	
	// startPosition MUST be the CENTER of the camera
	void init( const utility::Position& startPosition, int cameraWidth, int cameraHeight, 
				int newLevelWidth, int newLevelHeight );
	
	// destination MUST be the CENTER of the camera
	void move( utility::Position destination );

};

#endif

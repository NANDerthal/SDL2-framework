#include "Camera.h"

Camera::Camera() {
	position.x = 0;
	position.y = 0;

	width = height = levelWidth = levelHeight = 0;
}

utility::Position Camera::getValidPosition( const utility::Position& center ) {
	utility::Position newPosition = { center.x - width/2, center.y - height/2 };
	if ( newPosition.x < 0 ) { 
		newPosition.x = 0;			
	} else if ( newPosition.x > levelWidth - width ) {
		newPosition.x = levelWidth - width;
	}

	if ( newPosition.y < 0 ) {
		newPosition.y = 0;			
	} else if ( newPosition.y > levelHeight - height ) {
		newPosition.y = levelHeight - height;
	}

	return newPosition;
}

utility::Position Camera::getPosition() {
	return position;
}

void Camera::init( const utility::Position& startPosition, int cameraWidth, int cameraHeight, 
					int newLevelWidth, int newLevelHeight ) {
	position = getValidPosition( startPosition );

	width = cameraWidth;
	height = cameraHeight;

	levelWidth = newLevelWidth;
	levelHeight = newLevelHeight;
}

void Camera::move( utility::Position destination ) {
	position = getValidPosition( destination );	
}

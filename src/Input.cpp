#include "Input.h"

Input::Input() {
	currentMode = MENU;
}

void Input::changeMode( InputMode newMode ) {
	currentMode = newMode;
}

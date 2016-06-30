# SDL2-framework

This is a collection of a few game-relevant classes and their implementations. In particular, these were created for a 2D side-scroller.

Dependencies:
* SDL2
* SDL2 image
* SDL2 ttf

To see a demo program using the Makefile, clone the repo locally and type `make test-release`.

To see a demo program using CMake, clone the repo locally and type `cmake -H. -Bbuild` and then `cmake --build build --`.

Please note that this implementation is incomplete and likely will not be further developed, since much of the functionality the developers desire is more conveniently implemented with a combination of SDL2 and OpenGL rather than pure SDL2.

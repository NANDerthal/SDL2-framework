# SDL2-framework

This is a collection of a few game-relevant classes and their implementations. In particular, these were created for a 2D side-scroller.

Dependencies:
* SDL2
* SDL2 image
* SDL2 ttf

To see a demo program using the Makefile, type:
	
	git clone https://github.com/NANDerthal/SDL2-framework.git
	cd SDL2-framework
	make test-release
	./test.out
	

To see a demo program using CMake, type:
	
	git clone https://github.com/NANDerthal/SDL2-framework.git
	cd SDL2-framework
	cmake -H. -Bbuild
	cmake --build build --
	./build/Test
	

Please note that this implementation is incomplete and likely will not be further developed, since much of the functionality the developers desire is more conveniently implemented with a combination of SDL2 and OpenGL rather than pure SDL2.

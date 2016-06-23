OBJS = src/Main.cpp src/Game.cpp src/Game.h src/Window.cpp src/Window.h src/Sprite.cpp src/Sprite.h

CC = g++ 

COMPILER_FLAGS = -w -std=c++11 -O3

LINKER_FLAGS = -lSDL2 -lSDL_image

OBJ_NAME = output

all : $(OBJS)
	    $(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean :
	    \rm  *.o *~ $(OBJ_NAME)

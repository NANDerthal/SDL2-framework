OBJS = src/Window.cpp src/Window.h src/Sprite.cpp src/Sprite.h
MAIN = src/Game.h src/Game.cpp src/Main.cpp
TEST = src/Test.cpp

CC = g++ 

COMPILER_FLAGS = -w -std=c++11 -O3

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = output

all : $(OBJS) $(MAIN)
	    $(CC) $(OBJS) $(MAIN) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
test : $(OBJS) $(TEST)
	    $(CC) $(OBJS) $(TEST) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean :
	    \rm  *.o *~ $(OBJ_NAME)

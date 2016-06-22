OBJS = src/Window.cpp src/Window.h 

CC = g++ 

COMPILER_FLAGS = -w -std=c++11 -O3

LINKER_FLAGS = -lSDL2

OBJ_NAME = output

all : $(OBJS)
	    $(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean :
	    \rm  *.o *~ $(OBJ_NAME)

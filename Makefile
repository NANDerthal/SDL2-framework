OBJS = src/Window.cpp src/Window.h src/Sprite.cpp src/Sprite.h src/Animation.cpp src/Animation.h src/Background.cpp src/Background.h src/Parallax.cpp src/Parallax.h src/utility.cpp src/utility.hpp
MAIN = src/Game.h src/Game.cpp src/Main.cpp
TEST = src/Test.cpp

CC = g++ 

COMPILER_FLAGS = -w -std=c++11 -O3

LINKER_FLAGS = -lSDL2 -lSDL2_image

ALL_NAME = output

TEST_NAME = test

OBJ_NAMES = $(ALL_NAME) $(TEST_NAME)

# ========== UBUNTU ==========

all : game test

game: $(OBJS) $(MAIN)
	$(CC) $(OBJS) $(MAIN) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(ALL_NAME)
test : $(OBJS) $(TEST)
	$(CC) $(OBJS) $(TEST) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(TEST_NAME)

# ========== WINDOWS WITH MINGW ==========
INCLUDE_PATHS_W = -IC:\mingw_dev_lib\cross-tools\x86_64-w64-mingw32\include\SDL2 
LIBRARY_PATHS_W = -LC:\mingw_dev_lib\cross-tools\x86_64-w64-mingw32\lib
COMPILER_FLAGS_W = -w -std=c++11 -O3 -Wl,-subsystem,windows
LINKER_FLAGS_W = -lSDL2main

allw: gamew testw

gamew: $(OBJS) $(MAIN)
	$(CC) $(OBJS) $(MAIN) $(INCLUDE_PATHS_W) $(LIBRARY_PATHS_W) $(COMPILER_FLAGS_W) $(LINKER_FLAGS_W) $(LINKER_FLAGS) -o $(ALL_NAME)

testw: $(OBJS) $(TEST)
	$(CC) $(OBJS) $(TEST) $(INCLUDE_PATHS_W) $(LIBRARY_PATHS_W) $(COMPILER_FLAGS_W) $(LINKER_FLAGS_W) $(LINKER_FLAGS) -o $(TEST_NAME)

# ====================
clean :
	\rm  *.o *.exe *~ $(OBJ_NAMES)

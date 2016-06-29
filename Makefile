OBJS = src/Window.cpp src/Window.h src/Sprite.cpp src/Sprite.h src/Animation.cpp src/Animation.h src/Background.cpp src/Background.h src/Parallax.cpp src/Parallax.h src/utility.cpp src/utility.hpp src/Input.cpp src/Input.h src/Camera.cpp src/Camera.h
MAIN = src/Game.h src/Game.cpp src/Main.cpp
TEST = src/Test.cpp

CC = g++ 

COMPILER_FLAGS = -w -std=c++11
RELEASE_FLAGS = -O3
DEBUG_FLAGS = --debug

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

ALL_NAME = output

TEST_NAME = test

OBJ_NAMES = $(ALL_NAME) $(TEST_NAME)

# ========== UBUNTU ==========

all : game test

game: $(OBJS) $(MAIN)
	$(CC) $(OBJS) $(MAIN) $(COMPILER_FLAGS) $(RELEASE_FLAGS) $(LINKER_FLAGS) -o $(ALL_NAME)
test: $(OBJS) $(TEST)
	$(CC) $(OBJS) $(TEST) $(COMPILER_FLAGS) $(RELEASE_FLAGS) $(LINKER_FLAGS) -o $(TEST_NAME)
test-debug: $(OBJS) $(TEST)
	$(CC) $(OBJS) $(TEST) $(COMPILER_FLAGS) $(DEBUG_FLAGS) $(LINKER_FLAGS) -o $(TEST_NAME)
debug-leak:
	valgrind --leak-check=full --track-origins=yes --leak-resolution=high --show-reachable=yes ./$(TEST_NAME)

# ========== WINDOWS WITH MINGW ==========
INCLUDE_PATHS_W = -IC:\mingw_dev_lib\cross-tools\x86_64-w64-mingw32\include\SDL2 
LIBRARY_PATHS_W = -LC:\mingw_dev_lib\cross-tools\x86_64-w64-mingw32\lib
COMPILER_FLAGS_W = -w -std=c++11 -O3 -Wl,-subsystem,windows -DUSING_WINDOWS
LINKER_FLAGS_W = -lSDL2main

allw: gamew testw

gamew: $(OBJS) $(MAIN)
	$(CC) $(OBJS) $(MAIN) $(INCLUDE_PATHS_W) $(LIBRARY_PATHS_W) $(COMPILER_FLAGS_W) $(LINKER_FLAGS_W) $(LINKER_FLAGS) -o $(ALL_NAME)

testw: $(OBJS) $(TEST)
	$(CC) $(OBJS) $(TEST) $(INCLUDE_PATHS_W) $(LIBRARY_PATHS_W) $(COMPILER_FLAGS_W) $(LINKER_FLAGS_W) $(LINKER_FLAGS) -o $(TEST_NAME)

# ====================
clean :
	\rm  *.o *.exe *~ $(OBJ_NAMES)

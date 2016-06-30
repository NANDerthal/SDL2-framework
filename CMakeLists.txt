cmake_minimum_required( VERSION 3.5 )
project( SDL2-framework )

# version number
set( Test_VERSION_MAJOR 0 )
set( Test_VERSION_MINOR 1 )

# cmake search paths
list( APPEND CMAKE_PREFIX_PATH ${SRC} ${INCLUDE} )

# directories
set( SRC ${PROJECT_SOURCE_DIR}/src )
set( INCLUDE ${PROJECT_SOURCE_DIR}/include )
set( BIN ${PROJECT_SOURCE_DIR}/bin )
set( LIB ${PROJECT_SOURCE_DIR}/lib )

# header search paths
include_directories(
	${SRC}
	${INCLUDE}
	${BIN}
	${LIB}
)

# sources
file( GLOB_RECURSE LIBRARY_SOURCES "${LIB}/*.cpp" )
file( GLOB_RECURSE LIBRARY_HEADERS "${INCLUDE}/*.h" )

# compiler information
set( CMAKE_CXX_COMPILER g++ )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w" )

# libraries
add_library( SDL2-framework-lib ${LIBRARY_SOURCES} )
include_directories( "${PROJECT_SOURCE_DIR}/SDL2-framework-lib" )

# add executable (build target)
add_executable( Test ${SRC}/test.cpp )
target_link_libraries( Test SDL2-framework-lib SDL2 SDL2_image SDL2_ttf )

add_executable( Main ${SRC}/main.cpp )
target_link_libraries( Main SDL2-framework-lib SDL2 SDL2_image SDL2_ttf )


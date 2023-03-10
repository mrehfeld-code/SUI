cmake_minimum_required(VERSION 3.10)

project(SUI-static)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

add_subdirectory("external/SDL")
add_subdirectory("external/SDL_image")
add_subdirectory("external/SDL_ttf")

set(SUI_LIBRARIES "SUI-static;SDL3-shared;SDL3_image;SDL3_ttf")

set(SUI_INCLUDE_DIRS 	"${CMAKE_CURRENT_LIST_DIR}/include"
						"${CMAKE_CURRENT_LIST_DIR}/external/SDL/include"
						"${CMAKE_CURRENT_LIST_DIR}/external/SDL_image/include"
						"${CMAKE_CURRENT_LIST_DIR}/external/SDL_ttf/include")

file(GLOB SUI_SOURCE_FILES 	"src/*.cpp"
							"src/*.c")
add_library(SUI-static STATIC ${SUI_SOURCE_FILES})

target_link_libraries(SUI-static PUBLIC "SDL3-shared;SDL3_image;SDL3_ttf")
target_include_directories(SUI-static PUBLIC ${SUI_INCLUDE_DIRS})

add_subdirectory("test/")

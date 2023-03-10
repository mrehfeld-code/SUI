cmake_minimum_required(VERSION 3.10)

project(SUItest)

set(CMAKE_CXX_STANDARD 11)

add_executable(SUItest "src/main.cpp")

target_link_libraries(SUItest PUBLIC ${SUI_LIBRARIES})
target_include_directories(SUItest PUBLIC ${SUI_INCLUDE_DIRS})

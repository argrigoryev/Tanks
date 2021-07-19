cmake_minimum_required(VERSION 3.17)
project(Tanks C)

set(CMAKE_C_STANDARD 11)

#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})

add_executable(Tanks main.c tank.c tank.h bullet.c bullet.h network.c network.h)

#target_link_libraries(Tanks ${CURSES_LIBRARIES})

target_link_libraries(${PROJECT_NAME} ncurses)
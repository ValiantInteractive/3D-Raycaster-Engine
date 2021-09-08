cmake_minimum_required(VERSION 3.20)
project(RaycasterEngine C)

set(CMAKE_C_STANDARD 99)

add_executable(RaycasterEngine main.c maps.h raycaster.h structs.h)
target_link_libraries(RaycasterEngine -lm ${LIBS} -lglut -lGLEW -lGL -lGLU)
cmake_minimum_required(VERSION 3.25)
project(GameExercise C)

set(CMAKE_C_STANDARD 11)

add_executable(GameExercise test.c game.c game.h)

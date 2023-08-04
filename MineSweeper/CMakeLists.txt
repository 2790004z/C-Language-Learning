cmake_minimum_required(VERSION 3.25)
project(MineSweeper_ C)

set(CMAKE_C_STANDARD 99)

add_executable(MineSweeper_Easy_Version_ Client.c GameFunctionailty.c GameFunctionailty.h Menu.c Menu.h GameMap.c GameMap.h GameLauncher.c GameLauncher.h Constants.h)

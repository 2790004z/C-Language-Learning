//
// Created by Eason Zhang on 23/07/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NONE_MINE '_'
#define INIT_SHOW '*'
#define MINE 'M'
#define SEARCHED 'S'
#define MARK '#'

#define EASY_MODE 1
#define EASY_AMOUNT 10
#define EASY_MAP_SIZE 9
#define EASY_BOARD_SIZE (EASY_MAP_SIZE + 2)
#define MID_MODE 2
#define MID_AMOUNT 40
#define MID_MAP_SIZE 16
#define MID_BOARD_SIZE (MID_MAP_SIZE + 2)
#define DIFFICULT_MODE 3
#define DIFFICULT_AMOUNT 99
#define DIFFICULT_MAP_SIZE 24
#define DIFFICULT_BOARD_SIZE (DIFFICULT_MAP_SIZE + 2)

time_t startTime, endTime;
double gameTime;
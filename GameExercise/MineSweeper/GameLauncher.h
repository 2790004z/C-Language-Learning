//
// Created by Eason Zhang on 23/07/2023.
//

#pragma once
#include "Constants.h"
#include "GameFunctionailty.h"
#include "Menu.h"
#include "GameMap.h"


void gameBody();
void gamePlaying(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize, int mineAmount);
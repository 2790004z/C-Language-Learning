//
// Created by Eason Zhang on 18/07/2023.
//

#pragma once
#include "Constants.h"

void gamePlaying(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize, int mineAmount);
void setMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize, int mineAmount);
void markMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE],char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToMark, int colToMark, int mapSize);
bool searchMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToSearch, int colToSearch, int mapSize, int *winCounter);
int getMineData(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowIndex, int colIndex);
void autoSearch(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToSearch, int colToSearch, int *winCounter, int mapSize);

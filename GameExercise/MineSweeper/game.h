//
// Created by Eason Zhang on 18/07/2023.
//

#pragma once
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

void initialGame(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[EASY_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int boardSize);
void displayGameBoard(char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize);
void gameBody(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize, int mineAmount);
void setMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize, int mineAmount);
void markMine(char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToMark, int colToMark, int mapSize);
bool searchMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToSearch, int colToSearch, int mapSize, int *winCounter);
int getMineData(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowIndex, int colIndex);
void autoSearch(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToSearch, int colToSearch, int *winCounter, int mapSize);

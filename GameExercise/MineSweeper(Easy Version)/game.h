//
// Created by Eason Zhang on 18/07/2023.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAP_SIZE 9
#define BOARD_SIZE MAP_SIZE+2

#define NONE_MINE '_'
#define INIT_SHOW '*'
#define MINE 'M'
#define SEARCHED 'S'
#define MARK '#'

#define EASY 10


void initialGame(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int boardSize);
void displayGameBoard(char displayBoard[BOARD_SIZE][BOARD_SIZE], int mapSize);
void gameBody(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int mapSize, int difficulty);
void setMine(char mineBoard[BOARD_SIZE][BOARD_SIZE], int mapSize, int amount);
void markMine(char displayBoard[BOARD_SIZE][BOARD_SIZE], int rowToMark, int colToMark, int mapSize);
bool searchMine(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int rowToSearch, int colToSearch, int mapSize, int *winCounter);
int getMineData(char mineBoard[BOARD_SIZE][BOARD_SIZE], int rowIndex, int colIndex);
void autoSearch(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int rowToSearch, int colToSearch, int *winCounter, int mapSize);

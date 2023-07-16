//
// Created by Eason Zhang on 14/07/2023.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define COLM 3
#define ROW 3

void initialBoard(char board[ROW][COLM], int row, int colm);
void displayBoard(char board[ROW][COLM], int row, int colm);
void playerOperate(char board[3][3]);
void computerOperate(char board[ROW][COLM], int row, int colm);
bool checkCoordinate(char board[ROW][COLM], int row, int colm);
bool checkGameStatus(char board[ROW][COLM], int row, int colm);
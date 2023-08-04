//
// Created by Eason Zhang on 23/07/2023.
//

#include "GameMap.h"

void initialGame(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE],
                 char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE],
                 int boardSize) {
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            mineBoard[row][col] = NONE_MINE;
            displayBoard[row][col] = INIT_SHOW;
        }
    }
}

void displayGameBoard(char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize) {
    printf("----------Game Board----------\n");
    for (int col = 0; col <= mapSize; col++) {
        printf("%2d ｜", col);
    }
    printf("\n");

    for (int col = 0; col <= mapSize; col++){
        printf("-----");
    }
    printf("\n");


    for (int row = 1; row <= mapSize; row++) {
        printf("%2d |", row);
        for (int col = 1; col <= mapSize; col++) {
            printf(" %2c |", displayBoard[row][col]);
        }
        printf(" %2d |", row);
        printf("\n");
        for (int col = 0; col <= mapSize; col++){
            printf("-----");
        }
        printf("\n");
    }

    for (int col = 0; col <= mapSize; col++){
        printf("-----");
    }
    printf("\n");
    printf("----------------------------\n");
}
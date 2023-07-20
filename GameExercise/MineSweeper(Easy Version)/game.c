//
// Created by Eason Zhang on 18/07/2023.
//

#include "game.h"

void initialGame(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int boardSize) {
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            mineBoard[row][col] = NONE_MINE;
            displayBoard[row][col] = INIT_SHOW;
        }
    }
    setMine(mineBoard, MAP_SIZE, EASY);
}

void displayGameBoard(char displayBoard[BOARD_SIZE][BOARD_SIZE], int mapSize) {
    printf("----------Game Board----------\n");
    for (int col = 0; col <= mapSize; col++) {
        printf("%d  ", col);
    }
    printf("\n");
    for (int row = 1; row <= mapSize; row++) {
        printf("%d  ", row);
        for (int col = 1; col <= mapSize; col++) {
            printf("%c  ", displayBoard[row][col]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

void setMine(char mineBoard[BOARD_SIZE][BOARD_SIZE], int mapSize, int amount) {
    while (amount) {
        int row = rand() % mapSize + 1;
        int col = rand() % mapSize + 1;
        if (mineBoard[row][col] == NONE_MINE) {
            mineBoard[row][col] = MINE;
            amount--;
        }
    }
}

void markMine(char displayBoard[BOARD_SIZE][BOARD_SIZE], int rowToMark, int colToMark, int mapSize){
    if (displayBoard[rowToMark][colToMark] == INIT_SHOW) {
        printf("Marked (%d, %d).\n", rowToMark, colToMark);
        displayBoard[rowToMark][colToMark] = MARK;
    } else {
        if (displayBoard[rowToMark][rowToMark] == MARK){
            printf("(%d, %d) mark canceled.\n", rowToMark, colToMark);
            displayBoard[rowToMark][colToMark] = INIT_SHOW;
        }
    }
    displayGameBoard(displayBoard, mapSize);
}

int getMineData(char mineBoard[BOARD_SIZE][BOARD_SIZE], int rowIndex, int colIndex) {
    int result = 0;
    for (int rowCounter = -1; rowCounter <= 1; rowCounter++) {
        for (int colCounter = -1; colCounter <= 1; colCounter++) {
            if (mineBoard[rowCounter + rowIndex][colCounter + colIndex] == MINE) result++;
        }
    }
    return result;
}

void autoSearch(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int rowToSearch, int colToSearch, int *winCounter, int mapSize) {
    if (rowToSearch > 0 && rowToSearch <= mapSize && colToSearch > 0 && colToSearch <= mapSize) {
        if (mineBoard[rowToSearch][colToSearch] != SEARCHED) {
            mineBoard[rowToSearch][colToSearch] = SEARCHED;

            if (getMineData(mineBoard, rowToSearch, colToSearch)) {
                displayBoard[rowToSearch][colToSearch] = '0' + getMineData(mineBoard, rowToSearch, colToSearch);
                (*winCounter)--;
            } else {
                displayBoard[rowToSearch][colToSearch] = ' ';
                (*winCounter)--;
                for (int rowCounter = -1; rowCounter <= 1; rowCounter++) {
                    for (int colCounter = -1; colCounter <= 1; colCounter++) {
                        autoSearch(mineBoard, displayBoard, rowToSearch + rowCounter, colToSearch + colCounter, winCounter, mapSize);
                    }
                }
            }
        }
    }
}

bool searchMine(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int rowToSearch, int colToSearch, int mapSize, int *winCounter) {
    if (rowToSearch < 1 || rowToSearch > mapSize || colToSearch < 1 || colToSearch > mapSize) {
        printf("Invalid coordinate, please reenter.\n");
    } else {
        if (mineBoard[rowToSearch][colToSearch] == MINE) {
            return true;
        } else {
            autoSearch(mineBoard, displayBoard, rowToSearch, colToSearch, winCounter, mapSize);
            displayGameBoard(displayBoard, mapSize);
        }
    }
    return false;
}

void gameBody(char mineBoard[BOARD_SIZE][BOARD_SIZE], char displayBoard[BOARD_SIZE][BOARD_SIZE], int mapSize, int difficulty) {
    int winCounter = mapSize * mapSize - difficulty;
    bool isEnd = false;

    while (winCounter && !isEnd) {
        printf("\n");
        printf("------------------------------\n");
        printf("--------1. Search Mine--------\n");
        printf("---------2. Mark Mine---------\n");
        printf("------------------------------\n");
        printf("\n");


        printf("Give out you operation (eg: operation row col) :>");
        int operation = 0;
        int rowToOperate = 0;
        int colToOperate = 0;
        scanf("%d %d %d", &operation, &rowToOperate, &colToOperate);

        switch (operation) {
            case 1:
                isEnd = searchMine(mineBoard, displayBoard, rowToOperate, colToOperate, mapSize, &winCounter);
                break;
            case 2:
                markMine(displayBoard, rowToOperate, colToOperate, mapSize);
                break;
            default:
                printf("Error, reenter your choice.\n");
                break;
        }
    }
    if (winCounter == 0) {
        printf("Congratulations, you win!\n");
    } else {
        printf("You lose! Game over!\n");
    }
    displayGameBoard(mineBoard, mapSize);
}
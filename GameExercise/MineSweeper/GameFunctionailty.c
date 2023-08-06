//
// Created by Eason Zhang on 18/07/2023.
//

#include "GameLauncher.h"

void setMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize, int mineAmount) {
    while (mineAmount) {
        int row = rand() % mapSize + 1;
        int col = rand() % mapSize + 1;
        if (mineBoard[row][col] == NONE_MINE) {
            mineBoard[row][col] = MINE;
            mineAmount--;
        }
    }
}

void markMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE],char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToMark, int colToMark, int mapSize){

    if (displayBoard[rowToMark][colToMark] != INIT_SHOW && displayBoard[rowToMark][colToMark] != MARK) {
        printf("This place is searched, can't mark this place.\n");
    } else if (displayBoard[rowToMark][colToMark] == INIT_SHOW) {
        printf("Marked (%d, %d).\n", rowToMark, colToMark);
        displayBoard[rowToMark][colToMark] = MARK;
    } else if (displayBoard[rowToMark][colToMark] == MARK) {
        printf("(%d, %d) mark canceled.\n", rowToMark, colToMark);
        displayBoard[rowToMark][colToMark] = INIT_SHOW;
    }
    displayGameBoard(displayBoard, mapSize);
}

int getMineData(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowIndex, int colIndex) {
    int result = 0;
    for (int rowCounter = -1; rowCounter <= 1; rowCounter++) {
        for (int colCounter = -1; colCounter <= 1; colCounter++) {
            if (mineBoard[rowCounter + rowIndex][colCounter + colIndex] == MINE) result++;
        }
    }
    return result;
}

void autoSearch(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE],
                char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE],
                int rowToSearch, int colToSearch, int *winCounter, int mapSize) {
    if (rowToSearch > 0 && rowToSearch <= mapSize && colToSearch > 0 && colToSearch <= mapSize) {
        if (mineBoard[rowToSearch][colToSearch] != SEARCHED) {
            mineBoard[rowToSearch][colToSearch] = SEARCHED;

            if (getMineData(mineBoard, rowToSearch, colToSearch)) {
                displayBoard[rowToSearch][colToSearch] = '0' + getMineData(mineBoard, rowToSearch, colToSearch);
                (*winCounter)--;
            } else {
                if (displayBoard[rowToSearch][colToSearch] != MARK){
                    displayBoard[rowToSearch][colToSearch] = ' ';
                    (*winCounter)--;
                }
                for (int rowCounter = -1; rowCounter <= 1; rowCounter++) {
                    for (int colCounter = -1; colCounter <= 1; colCounter++) {
                        autoSearch(mineBoard, displayBoard,
                                   rowToSearch + rowCounter,
                                   colToSearch + colCounter, winCounter, mapSize);
                    }
                }
            }
        }
    }
}

bool searchMine(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int rowToSearch, int colToSearch, int mapSize, int *winCounter) {
    if (rowToSearch < 1 || rowToSearch > mapSize || colToSearch < 1 || colToSearch > mapSize) {
        printf("Invalid coordinate, please reenter.\n");
    } else {
        if (displayBoard[rowToSearch][colToSearch] == MARK){
            printf("This place is marked, this place can't search.\n");
        }else if (mineBoard[rowToSearch][colToSearch] == MINE) {
            return true;
        } else if (mineBoard[rowToSearch][colToSearch] == SEARCHED || mineBoard[rowToSearch][colToSearch] == ' '){
            printf("This place is searched, please enter other place to search mine.\n");
        }else {
            autoSearch(mineBoard, displayBoard, rowToSearch, colToSearch, winCounter, mapSize);
        }
    }
    displayGameBoard(displayBoard, mapSize);
    return false;
}
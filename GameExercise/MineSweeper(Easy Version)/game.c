//
// Created by Eason Zhang on 18/07/2023.
//

#include "game.h"

void initialGame(char mine[BOARD_SIZE][BOARD_SIZE], char show[BOARD_SIZE][BOARD_SIZE], int boardSize) {
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            mine[row][col] = NONE_MINE;
            show[row][col] = INIT_SHOW;
        }
    }
    setMine(mine, MAP_SIZE, EASY);
}

void displayGameBoard(char show[BOARD_SIZE][BOARD_SIZE], int mapSize) {
    printf("----------Game Board----------\n");
    for (int col = 0; col <= mapSize; col++) {
        printf("%d  ", col);
    }
    printf("\n");
    for (int row = 1; row <= mapSize; row++) {
        printf("%d  ", row);
        for (int col = 1; col <= mapSize; col++) {
            printf("%c  ", show[row][col]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

void setMine(char mine[BOARD_SIZE][BOARD_SIZE], int mapSize, int amount) {
    while (amount) {
        int row = rand() % mapSize + 1;
        int col = rand() % mapSize + 1;
        if (mine[row][col] == NONE_MINE) {
            mine[row][col] = MINE;
            amount--;
        }
    }
}

void markMine(char show[BOARD_SIZE][BOARD_SIZE], int rowToMark, int colToMark, int mapSize){
    if (show[rowToMark][colToMark] == INIT_SHOW) {
        printf("Marked (%d, %d).\n", rowToMark, colToMark);
        show[rowToMark][colToMark] = MARK;
    }else if (show[rowToMark][rowToMark] == MARK){
        printf("(%d, %d) mark canceled.\n", rowToMark, colToMark);
        show[rowToMark][colToMark] = INIT_SHOW;
    }
    displayGameBoard(show, mapSize);
}

int getMineData(char mine[BOARD_SIZE][BOARD_SIZE], int rowIndex, int colIndex) {
    int result = 0;
    for (int rowCounter = -1; rowCounter <= 1; rowCounter++) {
        for (int colCounter = -1; colCounter <= 1; colCounter++) {
            if (mine[rowCounter + rowIndex][colCounter + colIndex] == MINE) result++;
        }
    }
    return result;
}

void autoSearch(char mine[BOARD_SIZE][BOARD_SIZE], char show[BOARD_SIZE][BOARD_SIZE], int rowToSearch, int colToSearch, int *winCounter, int mapSize) {
    if (rowToSearch > 0 && rowToSearch <= mapSize && colToSearch > 0 && colToSearch <= mapSize) {
        if (mine[rowToSearch][colToSearch] != SEARCHED) {
            mine[rowToSearch][colToSearch] = SEARCHED;

            if (getMineData(mine, rowToSearch, colToSearch)) {
                show[rowToSearch][colToSearch] = '0' + getMineData(mine, rowToSearch, colToSearch);
                (*winCounter)--;
            } else {
                show[rowToSearch][colToSearch] = ' ';
                (*winCounter)--;
                for (int rowCounter = -1; rowCounter <= 1; rowCounter++) {
                    for (int colCounter = -1; colCounter <= 1; colCounter++) {
                        autoSearch(mine, show, rowToSearch + rowCounter, colToSearch + colCounter, winCounter, mapSize);
                    }
                }
            }
        }
    }
}

void gameBody(char mine[BOARD_SIZE][BOARD_SIZE], char show[BOARD_SIZE][BOARD_SIZE], int mapSize, int difficulty) {
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
                isEnd = searchMine(mine, show, rowToOperate, colToOperate, mapSize, &winCounter);
                break;
            case 2:
                markMine(show, rowToOperate, colToOperate, mapSize);
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
}

bool searchMine(char mine[BOARD_SIZE][BOARD_SIZE], char show[BOARD_SIZE][BOARD_SIZE], int rowToSearch, int colToSearch, int mapSize, int *winCounter) {
    if (rowToSearch < 1 || rowToSearch > mapSize || colToSearch < 1 || colToSearch > mapSize) {
        printf("Invalid coordinate, please reenter.\n");
    } else {
        if (mine[rowToSearch][colToSearch] == MINE) {
            return true;
        } else {
            autoSearch(mine, show, rowToSearch, colToSearch, winCounter, mapSize);
            displayGameBoard(show, mapSize);
        }
    }
    return false;
}

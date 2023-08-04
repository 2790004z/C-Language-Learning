//
// Created by Eason Zhang on 23/07/2023.
//

#include "GameLauncher.h"

void gameBody(){
    difficultyMenu();
    int difficulty = 0;
    int boardSize = 0;
    int mapSize = 0;
    int mineAmount = 0;
    scanf("%d", &difficulty);
    char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE] = {0};
    char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE] = {0};

    switch (difficulty) {
        case EASY_MODE:
            boardSize = EASY_BOARD_SIZE;
            mapSize = EASY_MAP_SIZE;
            mineAmount = EASY_AMOUNT;
            break;
        case MID_MODE:
            boardSize = MID_BOARD_SIZE;
            mapSize = MID_MAP_SIZE;
            mineAmount = MID_AMOUNT;
            break;
        case DIFFICULT_MODE:
            boardSize = DIFFICULT_BOARD_SIZE;
            mapSize = DIFFICULT_MAP_SIZE;
            mineAmount = DIFFICULT_AMOUNT;
            break;
        default:
            printf("Error, please reenter your choice.\n");
    }

    // Initialisation and Set Mine in Map
    initialGame(mineBoard, displayBoard, boardSize);
    // Set mine
    setMine(mineBoard, mapSize, mineAmount);
    // Display gameBody board
    displayGameBoard(displayBoard, mapSize);
    // Start Search Mine
    gamePlaying(mineBoard, displayBoard, mapSize, mineAmount);
}

void gamePlaying(char mineBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], char displayBoard[DIFFICULT_BOARD_SIZE][DIFFICULT_BOARD_SIZE], int mapSize, int mineAmount) {
    // Timer
    startTime = time(NULL);
    int winCounter = mapSize * mapSize - mineAmount;
    bool isEnd = false;

    while (winCounter && !isEnd) {
        optionsMenu();

        int operation = 0;
        int rowToOperate = 0;
        int colToOperate = 0;
        scanf("%d %d %d", &operation, &rowToOperate, &colToOperate);

        switch (operation) {
            case 1:
                isEnd = searchMine(mineBoard, displayBoard, rowToOperate, colToOperate, mapSize, &winCounter);
                break;
            case 2:
                markMine(mineBoard, displayBoard, rowToOperate, colToOperate, mapSize);
                break;
            default:
                printf("Error, reenter your choice.\n");
                break;
        }
    }
    endTime = time(NULL);
    gameTime = difftime(endTime, startTime);

    printf("This game you have played %.0f seconds.\n", gameTime);
    if (winCounter == 0) {
        printf("Congratulations, you win!\n");
    } else {
        printf("You lose! Game over!\n");
    }
    printf("This game you have played %.0f seconds.\n", gameTime);
    displayGameBoard(mineBoard, mapSize);
}
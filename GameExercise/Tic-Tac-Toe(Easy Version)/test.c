//
// Created by Eason Zhang on 14/07/2023.
//


#include "game.h"

void menu() {
    printf("------------------------------");
    printf("----- 1. Play    0. Exit -----");
    printf("------------------------------\n");
}

void game() {
    char board[ROW][COLM] = {0};

    // Initialisation
    initialBoard(board, ROW, COLM);
    displayBoard(board, ROW, COLM);

    // Start Game
    bool isWin = false;
    while (!isWin){
        playerOperate(board);
        isWin = checkGameStatus(board, ROW, COLM);
        if (isWin) break;
        computerOperate(board, ROW, COLM);
        isWin = checkGameStatus(board, ROW, COLM);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    int input = 0;
    do {
        menu();
        printf("Enter Your Choice:>");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("Welcome!\n");
                game();
                break;
            case 0:
                printf("Exit!\n");
                break;
            default:
                printf("Error\n");
                break;
        }
    } while (input);
    return 0;
}
#include "game.h"


void mainMenu() {
    printf("------------------------------\n");
    printf("----- 1. Play    0. Exit -----\n");
    printf("------------------------------\n");
}

void game(){
    char mineBoard[BOARD_SIZE][BOARD_SIZE] = {0};
    char displayBoard[BOARD_SIZE][BOARD_SIZE] = {0};

    // Initialisation and Set Mine in Map
    initialGame(mineBoard, displayBoard, BOARD_SIZE);
    // Display game board
    displayGameBoard(displayBoard, MAP_SIZE);
    // Start Search Mine
    gameBody(mineBoard, displayBoard, MAP_SIZE, EASY);
}


int main() {
    // Set the start point of the random number;
    srand((unsigned int) time(NULL));
    int option = 0;
    do{
        mainMenu();
        printf("Enter Your Choice:>");
        scanf("%d", &option);

        switch (option) {
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
    } while (option);
    return 0;
}

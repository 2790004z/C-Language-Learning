#include "game.h"


void mainMenu() {
    printf("------------------------------\n");
    printf("----- 1. Play    0. Exit -----\n");
    printf("------------------------------\n");
}

void game(){
    char mine[BOARD_SIZE][BOARD_SIZE] = {0};
    char show[BOARD_SIZE][BOARD_SIZE] = {0};

    // Initialisation and Set Mine in Map
    initialGame(mine, show, BOARD_SIZE);
    // Display game board
    displayGameBoard(show, MAP_SIZE);
    // Start Search Mine
    gameBody(mine, show, MAP_SIZE, EASY);
}


int main() {
    // Set the start point of the random number;
    srand((unsigned int) time(NULL));
    int input = 0;
    do{
        mainMenu();
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

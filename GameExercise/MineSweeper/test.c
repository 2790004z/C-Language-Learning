#include "game.h"


void mainMenu() {
    printf("------------------------------\n");
    printf("----- 1. Play    0. Exit -----\n");
    printf("------------------------------\n");
}

void difficultyMenu() {
    printf("------------------------------\n");
    printf("-1. Easy 2. Mid  3.Difficult -\n");
    printf("------------------------------\n");
    printf("Choose difficulty:>");
}

void game(){
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
    // Display game board
    displayGameBoard(displayBoard, mapSize);
    // Start Search Mine
    gameBody(mineBoard, displayBoard, mapSize, mineAmount);
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

#include "Menu.h"
#include "GameLauncher.h"


int main() {
    // Set the start point of the random number;
    srand((unsigned int) time(NULL));
    int option = 0;
    do{
        mainMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Welcome!\n");
                gameBody();
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

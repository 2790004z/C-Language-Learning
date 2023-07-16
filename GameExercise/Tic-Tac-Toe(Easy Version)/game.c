//
// Created by Eason Zhang on 14/07/2023.
//

#include "game.h"

void initialBoard(char board[ROW][COLM], int row, int col){
    for(int rowCounter = 0; rowCounter < row; rowCounter++){
        for(int colmCounter = 0; colmCounter < col; colmCounter++){
            board[rowCounter][colmCounter] = ' ';
        }
    }
}

void displayBoard(char board[ROW][COLM], int row, int col){
    printf("----------Board----------\n");
    for(int rowCounter = 0; rowCounter < row; rowCounter++){
        printf(" ");
        for (int colmCounter = 0; colmCounter < col; colmCounter++){
            if (colmCounter == col-1){
                printf(" %c ", board[rowCounter][colmCounter]);
                if (rowCounter != row-1){
                    for(int counter = 0; counter < col; counter++){
                        switch (counter) {
                            case 0:
                                printf("\n----");
                                break;
                            case COLM-1:
                                printf("|----\n");
                                break;
                            default:
                                printf("|---");
                                break;
                        }
                    }
                } else printf("\n");
            } else printf(" %c |", board[rowCounter][colmCounter]);
        }
    }
    printf("-------------------------\n");
}

void playerOperate(char board[3][3]) {
    int x = 0;
    int y = 0;
    printf("Player Round:>\n");
    bool roundEnd = false;

    while(!roundEnd){
        printf("Give out coordinate of your chess (x y): ");
        scanf("%d %d", &x, &y);
        roundEnd = checkCoordinate(board, x, y);
        displayBoard(board, ROW, COLM);
    }
}

void computerOperate(char board[ROW][COLM], int row, int colm){
    printf("Computer Round:>\n");
    int x = rand() % row;
    int y = rand() % colm;
    bool roundEnd = false;

    while (!roundEnd){
        if (board[x][y] == ' '){
            board[x][y] = '#';
            roundEnd = true;
            displayBoard(board, ROW, COLM);
        } else{
            x = rand() % row;
            y = rand() % colm;
        }
    }

}

bool checkCoordinate(char board[ROW][COLM], int row, int col){
    if (row >= 0 && col>= 0 && row < ROW && col < COLM){
        if (board[row][col] == ' '){
            board[row][col] = '*';
            return true;
        } else{
            printf("This coordinate occupied, please enter other coordinate.\n");
        }
    } else{
        printf("Out of boundary, please enter other coordinate.\n");
    }
    return false;
}

bool checkGameStatus(char board[ROW][COLM], int row, int colm){
    int fullLine = 0;
    bool findWinner = false;
    char winner = ' ';
    // Default col == row
    for (int counter = 0; counter < row; counter++){
        if (board[counter][0] == board [counter][1] && board [counter][1] == board [counter][2] && board [counter][0] == board [counter][2]){
            if (board[counter][0] != ' ') {
                winner = board[counter][0];
                break;
            }
        }
        if (board[0][counter] == board[1][counter] && board[1][counter] == board[2][counter] && board[0][counter] == board[2][counter]){
            if (board[0][counter] != ' ') {
                winner = board[0][counter];
                break;
            }
        }
        if (board[counter][0] != ' ' && board[counter][1] != ' ' && board[counter][2] != ' '){
            fullLine ++;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == board[2][2]){
        if (board[0][0] != ' ') {
            winner = board[0][0];
        }
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0]){
        if (board[0][2] != ' ') {
            winner = board[0][2];
        }
    }

    switch (winner) {
        case '#':
            printf("Computer Win.\n");
            findWinner = true;
            break;
        case '*':
            printf("Player Win.\n");
            findWinner = true;
            break;
        default:
            if (fullLine == ROW){
                printf("Tie!\n");
                findWinner = true;
                break;
            } else findWinner = false;
            break;
    }
    if (findWinner) displayBoard(board, ROW, COLM);
    return findWinner;
}
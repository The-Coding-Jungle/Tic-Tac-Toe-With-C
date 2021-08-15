#include "printFunctions.h"
#include <stdlib.h>
typedef enum {false, true} bool;

bool checkWin(char game[][3], char currentTurn) {
    if (game[1][1] == currentTurn) {
        if (game[0][0] == currentTurn && game[2][2] == currentTurn) {
            return true;
        } else if (game[0][2] == currentTurn && game[2][0] == currentTurn) {
            return true;
        } else if (game[0][1] == currentTurn && game[2][1] == currentTurn) {
            return true;
        } else if (game[1][0] == currentTurn && game[1][2] == currentTurn) {
            return true;
        }
    } else {
        if (game[0][0] == currentTurn && game[0][1] == currentTurn && game[0][2] == currentTurn) {
            return true;
        } else if (game[2][0] == currentTurn && game[2][1] == currentTurn && game[2][2] == currentTurn) {
            return true;
        } else if (game[0][0] == currentTurn && game[1][0] == currentTurn && game[2][0] == currentTurn) {
            return true;
        } else if (game[2][0] == currentTurn && game[2][1] == currentTurn && game[2][2] == currentTurn) {
            return true;
        }
    } return false;
}

void newGame() {
    char currentTurn = 'x';
    char game[3][3];
    int numberOfTurns = 0, x, y;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game[i][j] = ' ';
        }
    }

    while (numberOfTurns < 9) {
        printGame(game);
        printf("%c's turn. Enter the move: ", currentTurn);
        scanf("%d %d", &x, &y);

        if (game[x][y] == ' ') {
            // Can make the move as this place is valid.
            game[x][y] = currentTurn;
            if (checkWin(game, currentTurn)) {
                printf("%c wins!\n", currentTurn);
                printGame(game);
                return;
            }
            currentTurn = (currentTurn == 'x') ? 'o' : 'x';
            numberOfTurns++;
        } else {
            printf("Invalid move\n");
        }
    }

    if (numberOfTurns == 9) {
        printf("Draw\n");
    } 
}

void makeRandomMove(char game[][3], int* x, int* y) {
    int x1, y1;

    do {
        *x = rand() % 3; 
        *y = rand() % 3;
    } while (game[*x][*y] != ' ');
}

void newOnePlayerGame() {
    char currentTurn = 'x';
    char game[3][3];
    int numberOfTurns = 0, x, y;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game[i][j] = ' ';
        }
    }

    while (numberOfTurns < 8) {
        printGame(game);
        printf("Enter move: ");
        scanf("%d %d", &x, &y);
        if (game[x][y] == ' ') {
            // Can make the move as this place is valid.
            game[x][y] = currentTurn;
            if (checkWin(game, currentTurn)) {
                printf("x wins\n");
                break;
            } 

            currentTurn = 'o';
            makeRandomMove(game, &x, &y);

            game[x][y] = currentTurn;
            if (checkWin(game, currentTurn)) {
                printf("o wins\n");
                break;
            } 
            currentTurn = 'x';
            

            numberOfTurns+=2;     
        } else {
            printf("Invalid move\n");
        }
    }

    while (numberOfTurns == 8) {
        printGame(game);
        printf("Enter move: ");
        scanf("%d %d", &x, &y);

        if (game[x][y] == ' ') {
            // Can make the move as this place is valid.
            game[x][y] = currentTurn;
            if (checkWin(game, currentTurn)) {
                printf("x wins!\n", currentTurn);
            } else {
                printf("Draw\n");
            } 
            break;
        } else {
            printf("Invalid move\n");
        }
    }
}
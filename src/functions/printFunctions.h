#include <stdio.h>

void printGame(char game[][3]) {
    printf("Current Game\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("| %c ", game[i][j]);
        } printf("|\n");
    }
}

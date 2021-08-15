#if _WIN32 || __CYGWIN__ 
    #include "functions\gameplay.h"
#else 
    #include "functions/gameplay.h"
#endif 

int main() {
    char option;
    
    do {
        printf("Enter 1 to start 1 player game\n");
        printf("Enter 2 to start 2 player game\n");
        printf("Enter q to quit\n");
        printf("Enter the option: ");
        scanf(" %c", &option);
        if (option == '2') {
            newGame();
        } else if (option == '1') {
            newOnePlayerGame();
        } else if (option == 'q' || option == 'Q') {

        } else {
            printf("Invalid option.\n");
        }
    } while (option != 'q' && option != 'Q');

    
    return 0;
}
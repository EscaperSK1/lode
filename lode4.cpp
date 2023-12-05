// lode4.cpp : Defines the entry point for the application.
//

#include "lode4.h"
#include "game.h"
#include "board.h"
#include "battleship.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define SHIP 'S'
#define HIT 'X'
#define WATER 'O'

using namespace std;

int main() {
    srand(time(NULL));

    printf("Welcome to the Battleship game!\n");

    while (1) {
        printf("Choose a game mode:\n");
        printf("1. Single-player\n");
        printf("2. Multi-player\n");
        printf("3. Quit\n");

        int choice;
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            singlePlayerGame();
            break;
        case 2:
            multiPlayerGame();
            break;
        case 3:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

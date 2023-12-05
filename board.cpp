// board.c
#include "board.h"
#include "battleship.h"
#include <stdio.h>

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = WATER;
        }
    }
}

void printPlayerBoard(char board[BOARD_SIZE][BOARD_SIZE], int hideShips) {
    printBoard(board, hideShips);
}

void printComputerBoard(char board[BOARD_SIZE][BOARD_SIZE], int hideShips) {
    printBoard(board, hideShips);
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int hideShips) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char cell = board[i][j];
            if (cell == SHIP && hideShips) {
                printf("%c ", WATER);
            }
            else {
                printf("%c ", cell);
            }
        }
        printf("\n");
    }
}

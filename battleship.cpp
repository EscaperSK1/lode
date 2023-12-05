// battleship.c
#include "battleship.h"
#include <stdio.h>

void placeShip(char board[BOARD_SIZE][BOARD_SIZE], Ship ship) {
    for (int i = ship.start.row; i <= ship.end.row; i++) {
        for (int j = ship.start.col; j <= ship.end.col; j++) {
            board[i][j] = SHIP;
        }
    }
}

int isHit(char board[BOARD_SIZE][BOARD_SIZE], Coordinate shot) {
    return board[shot.row][shot.col] == SHIP;
}

void updateBoard(char board[BOARD_SIZE][BOARD_SIZE], Coordinate shot) {
    if (isHit(board, shot)) {
        printf("Hit!\n");
        board[shot.row][shot.col] = HIT;
    }
    else {
        printf("Miss!\n");
        board[shot.row][shot.col] = WATER;
    }
}

int isValidShot(char board[BOARD_SIZE][BOARD_SIZE], Coordinate shot) {
    return 0 <= shot.row && shot.row < BOARD_SIZE &&
        0 <= shot.col && shot.col < BOARD_SIZE &&
        board[shot.row][shot.col] != HIT;
}

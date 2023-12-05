#pragma once

#define BATTLESHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define SHIP 'S'
#define HIT 'X'
#define WATER 'O'

typedef struct {
    int row;
    int col;
} Coordinate;

typedef struct {
    Coordinate start;
    Coordinate end;
} Ship;

void placeShip(char board[BOARD_SIZE][BOARD_SIZE], Ship ship);
int isHit(char board[BOARD_SIZE][BOARD_SIZE], Coordinate shot);
void updateBoard(char board[BOARD_SIZE][BOARD_SIZE], Coordinate shot);
int isValidShot(char board[BOARD_SIZE][BOARD_SIZE], Coordinate shot);


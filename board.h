#pragma once

#define BOARD_H

#include "battleship.h"

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printPlayerBoard(char board[BOARD_SIZE][BOARD_SIZE], int hideShips);
void printComputerBoard(char board[BOARD_SIZE][BOARD_SIZE], int hideShips);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int hideShips);

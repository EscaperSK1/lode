// game.c
#include "game.h"
#include "board.h"
#include "battleship.h"
#include <stdio.h>

void singlePlayerGame() {
    char playerBoard[BOARD_SIZE][BOARD_SIZE];
    char computerBoard[BOARD_SIZE][BOARD_SIZE];

    // Initialize boards
    initializeBoard(playerBoard);
    initializeBoard(computerBoard);

    // Place computer ships
    srand(time(NULL));
    Ship computerShips[] = { {{0, 0}, {0, 2}},
                            {{3, 5}, {6, 5}},
                            {{9, 9}, {9, 9}} };

    for (int i = 0; i < sizeof(computerShips) / sizeof(computerShips[0]); i++) {
        placeShip(computerBoard, computerShips[i]);
    }

    // Place player ships
    printf("Place your ships on the board.\n");
    Ship playerShips[] = { {{0, 0}, {0, 2}},
                          {{3, 5}, {6, 5}},
                          {{9, 9}, {9, 9}} };

    for (int i = 0; i < sizeof(playerShips) / sizeof(playerShips[0]); i++) {
        printPlayerBoard(playerBoard, 0);
        printf("Enter coordinates for ship %d (start row, start col, end row, end col): ", i + 1);
        scanf_s("%d %d %d %d", &playerShips[i].start.row, &playerShips[i].start.col,
            &playerShips[i].end.row, &playerShips[i].end.col);

        placeShip(playerBoard, playerShips[i]);
    }

    // Game loop
    int playerTurn = 1;
    while (1) {
        if (playerTurn) {
            // Player's turn
            printf("Your turn!\n");
            printComputerBoard(computerBoard, 1);

            Coordinate shot;
            printf("Enter your guess (row and column): ");
            scanf_s("%d %d", &shot.row, &shot.col);

            if (!isValidShot(computerBoard, shot)) {
                printf("Invalid guess. Try again.\n");
                continue;
            }

            updateBoard(computerBoard, shot);

            // Check if all computer ships are sunk
            int shipsRemaining = 0;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (computerBoard[i][j] == SHIP) {
                        shipsRemaining = 1;
                        break;
                    }
                }
                if (shipsRemaining) {
                    break;
                }
            }

            if (!shipsRemaining) {
                printf("Congratulations! You sunk all the computer's ships.\n");
                break;
            }
        }
        else {
            // Computer's turn
            printf("Computer's turn!\n");

            Coordinate shot;
            do {
                shot.row = rand() % BOARD_SIZE;
                shot.col = rand() % BOARD_SIZE;
            } while (!isValidShot(playerBoard, shot));

            updateBoard(playerBoard, shot);

            // Check if all player ships are sunk
            int shipsRemaining = 0;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (playerBoard[i][j] == SHIP) {
                        shipsRemaining = 1;
                        break;
                    }
                }
                if (shipsRemaining) {
                    break;
                }
            }

            if (!shipsRemaining) {
                printf("Sorry, the computer sunk all your ships. Better luck next time!\n");
                break;
            }
        }

        playerTurn = !playerTurn; // Switch turns
    }
}

void multiPlayerGame() {
    char player1Board[BOARD_SIZE][BOARD_SIZE];
    char player2Board[BOARD_SIZE][BOARD_SIZE];

    // Initialize boards
    initializeBoard(player1Board);
    initializeBoard(player2Board);

    // Place ships for both players
    printf("Player 1, place your ships on the board.\n");
    Ship player1Ships[] = { {{0, 0}, {0, 2}},
                           {{3, 5}, {6, 5}},
                           {{9, 9}, {9, 9}} };

    for (int i = 0; i < sizeof(player1Ships) / sizeof(player1Ships[0]); i++) {
        printPlayerBoard(player1Board, 0);
        printf("Enter coordinates for ship %d (start row, start col, end row, end col): ", i + 1);
        scanf_s("%d %d %d %d", &player1Ships[i].start.row, &player1Ships[i].start.col,
            &player1Ships[i].end.row, &player1Ships[i].end.col);

        placeShip(player1Board, player1Ships[i]);
    }

    printf("Player 2, place your ships on the board.\n");
    Ship player2Ships[] = { {{0, 0}, {0, 2}},
                           {{3, 5}, {6, 5}},
                           {{9, 9}, {9, 9}} };

    for (int i = 0; i < sizeof(player2Ships) / sizeof(player2Ships[0]); i++) {
        printPlayerBoard(player2Board, 0);
        printf("Enter coordinates for ship %d (start row, start col, end row, end col): ", i + 1);
        scanf_s("%d %d %d %d", &player2Ships[i].start.row, &player2Ships[i].start.col,
            &player2Ships[i].end.row, &player2Ships[i].end.col);

        placeShip(player2Board, player2Ships[i]);
    }

    // Game loop
    int playerTurn = 1;
    while (1) {
        if (playerTurn) {
            // Player 1's turn
            printf("Player 1's turn!\n");
            printPlayerBoard(player2Board, 1);

            Coordinate shot;
            printf("Enter your guess (row and column): ");
            scanf_s("%d %d", &shot.row, &shot.col);

            if (!isValidShot(player2Board, shot)) {
                printf("Invalid guess. Try again.\n");
                continue;
            }

            updateBoard(player2Board, shot);

            // Check if all player 2 ships are sunk
            int shipsRemaining = 0;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (player2Board[i][j] == SHIP) {
                        shipsRemaining = 1;
                        break;
                    }
                }
                if (shipsRemaining) {
                    break;
                }
            }

            if (!shipsRemaining) {
                printf("Player 1 won! Player 2's ships are all sunk.\n");
                break;
            }
        }
        else {
            // Player 2's turn
            printf("Player 2's turn!\n");
            printPlayerBoard(player1Board, 1);

            Coordinate shot;
            printf("Enter your guess (row and column): ");
            scanf_s("%d %d", &shot.row, &shot.col);

            if (!isValidShot(player1Board, shot)) {
                printf("Invalid guess. Try again.\n");
                continue;
            }

            updateBoard(player1Board, shot);

            // Check if all player 1 ships are sunk
            int shipsRemaining = 0;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (player1Board[i][j] == SHIP) {
                        shipsRemaining = 1;
                        break;
                    }
                }
                if (shipsRemaining) {
                    break;
                }
            }

            if (!shipsRemaining) {
                printf("Player 2 won! Player 1's ships are all sunk.\n");
                break;
            }
        }

        playerTurn = !playerTurn; // Switch turns
    }
}

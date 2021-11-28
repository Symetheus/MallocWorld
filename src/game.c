//
// Created by TimTim on 23/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "player.h"
#include "events.h"
#include "map.h"
#include "dialog.h"
#include "npc.h"
#include "inventory.h"

void runMain() {
    int choice;

    do {
        displayMenu(); // Display the text menu
        choice = getchar();
        getchar();

        switch(choice) {
            case '1': // New game
                //createMap();
                run();

                break;

            case '2': // Load game
                printf("Load game from save\n");
                break;

            case '3': // Display controls
                displayControls();
                break;

            case '4': // Display the list of all items (maybe une fonction de tri par type)
                printf("List of all items\n");
                break;

            case '5': // Exit
                printf("\nSee you soon !\n");
                exit(0); // terminates the complete program execution

            default:
                printf("This value is not a choice... Please try again\n");
                break;
        }

    } while(1);

}

void run() {
    clear_screen();

    Game* game = malloc( sizeof(Game) );
    game->player = newPlayer();
    game->npc = newNpc();


    int playerChoice;
    do {
        clear_screen();
        // Display the player's position
        //displayPlayerPosition(game->player.position);

        // Display the map
        displayMap();
        // Display player's inventory
        displayInventoryFromMaxCapacity(game->player.inventory);
        // Display actions that the player can do
        displayPlayerMenu();

        // Switch (player's actions)
        playerChoice = handlePlayerInput(game);

    } while(playerChoice != '3');

}


int handlePlayerInput(Game* game) {
    int playerChoice = getchar();
    getchar();

    switch(playerChoice) {
        case 'z': // Move up
            printf("Moving up\n");
            *game = checkFuturePosition(game, game->player.position.X, game->player.position.Y - 1);

            break;

        case 'q': // Move left
            printf("Moving left\n");
            *game = checkFuturePosition(game, game->player.position.X - 1, game->player.position.Y);
            /*if ( checkFuturePosition(game, game->player.position.X - 1, game->player.position.Y) ) {
                updatePlayerPositionOnMap(game->player.position, game->player.position.X - 1, game->player.position.Y);

                game->player.position = updatePlayerPosition(game->player.position, game->player.position.X - 1, game->player.position.Y);
            }*/
            break;

        case 's': // Move down
            printf("Moving down\n");
            *game = checkFuturePosition(game, game->player.position.X, game->player.position.Y + 1);
            /*if ( checkFuturePosition(game, game->player.position.X, game->player.position.Y + 1) ) {
                updatePlayerPositionOnMap(game->player.position, game->player.position.X, game->player.position.Y + 1);

                game->player.position = updatePlayerPosition(game->player.position, game->player.position.X, game->player.position.Y + 1);
            }*/
            break;

        case 'd': // Move right
            *game = checkFuturePosition(game, game->player.position.X + 1, game->player.position.Y);
            printf("Moving right\n");
            /*if ( checkFuturePosition(game, game->player.position.X + 1, game->player.position.Y) ) {
                updatePlayerPositionOnMap(game->player.position, game->player.position.X + 1, game->player.position.Y);

                game->player.position = updatePlayerPosition(game->player.position, game->player.position.X + 1, game->player.position.Y);
            }*/
            break;

        case 'i':
            displayInventoryMenu(game->player.inventory);
            break;

        case 'p': // Pause menu
            displayPauseMenu();
            playerChoice = getchar();
            getchar();

            if (playerChoice == '2') { // Save choice
                printf("Saving game...\n");
            }
            break;

        default:
            printf("This value is not a choice... Please try again\n");
            break;
    }

    return playerChoice;
}

/* void kill_game(Game *game) {
    killPlayer();
} */
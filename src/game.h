//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_GAME_H
#define MALLOC_WORLD_GAME_H

#include "types.h"
#include "generate.h"
#include "load.h"


void runMain();
void run(int choice);
void kill_game(Game* game);
int handlePlayerInput(Game* game);


#endif //MALLOC_WORLD_GAME_H

//
// Created by TimTim on 01/11/2021.
//

#ifndef MALLOC_WORLD_ITEM_H
#define MALLOC_WORLD_ITEM_H

#include "types.h"

#define MAX_DURABILITY 10;


void checkItemTypeForDisplay(Item item);
void displayWeapon(Item item);
void displayTool(Item item);
void displayCraft(Item item);
void displayArmor(Item item);
void displayHeal(Item item);


int checkItemDurability(int casePosition);
Inventory addItemToInventory(Inventory inventory);

#endif //MALLOC_WORLD_ITEM_H
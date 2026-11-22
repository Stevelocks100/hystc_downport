#ifndef PLAYER_H
#define PLAYER_H

#include "../include/globals.h"
#include <stdio.h>
#include "staminabar.h"
#include "room.h"
#include "vec2.h"
#include "model.h"

typedef enum {NORTH, EAST, SOUTH, WEST}Direction; 
typedef struct {
    Vec2 mapCoords;
    Cat (*playerCats)[CATS];    /*this should point to the model's cat array*/
    StaminaBar staminaBar;
    bool flashlight;
    Direction lookDir;
    bool safe;
    int speed;
    int move_timer;
    bool moving;
    Direction lastMoveDir;
}Player;

void movePlayer(Vec2 vec, Player* playerPtr, Room* roomPtr);

void turn(Player player, bool right);

void flashToggle(Player* player);
#endif

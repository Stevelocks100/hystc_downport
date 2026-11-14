#ifndef PLAYER_H
#define PLAYER_H

#include "../include/globals.h"
#include "../include/types.h"
#include "staminabar.h"
#include "room.h"
#include "vec2.h"

typedef enum {NORTH, EAST, SOUTH, WEST}Direction; 
typedef struct {
    Vec2 mapCoords;
    StaminaBar* staminaPtr;
    bool flashlight;
    Direction lookDir;
    bool safe;
    bool sprinting;
    int speed;
    int move_timer;
    Direction lastMoveDir;
}Player;

Vec2 movePlayer(Vec2 vec, Player* playerPtr, Room* roomPtr);

void flashToggle(Player* player);

void look(Player* player, Direction direction); 

bool isSafe(Player* player, int positionX, int positionY);//checks if the current tile is "safe"

void setSpeed(Player* player, int newSpeed);


#endif

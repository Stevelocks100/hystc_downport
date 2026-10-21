#ifndef PLAYER_H
#define PLAYER_H

#include "../include/globals.h"
#include "tile.h"

typedef enum {NORTH, EAST, SOUTH, WEST}Direction; 
typedef struct {
    int position[2]; //position[0] is x coord, position[1] is y coord
    bool flashlight;
    Direction direction;
    bool safe;
    int speed;
}Player;

void move(Player player, int positionX, int positionY);
    
void playerCollisionCheck(Player player, Tile tile);

void flashToggle(Player player);

void look(Player player, Direction direction); 

bool isSafe(Player player, int positionX, int positionY);//checks if the current tile is "safe"

void setSpeed(Player player, int newSpeed);


#endif

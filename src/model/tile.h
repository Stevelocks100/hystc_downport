#ifndef TILE_H
#define TILE_H

/*Tiles are the foundational object in our level structure.
Tiles store information about its type and what entities are on it
Rooms are 2D arrays of these tiles*/

#include "player.h"
#include "cat.h"
#include "copycat.h"
#include "noisetrap.h"

/* Tile */
typedef enum {NORMAL, SAFE, WALL, NOISETRAP, PROP, DISPOSALBIN, TERMINAL, EXIT, ELEVATOR}TileType;
typedef struct {
    TileType type;/*set upon loading room*/
    bool interactive;
}Tile;
#endif

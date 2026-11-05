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
    TileType type;
    /*pointers to objects on this tile*/
    Player *player;
    Cat *cat;
    CopyCat *copyCat;
    NoiseTrap trap;
}Tile;

Tile movePlayer(Tile* startPtr, Tile* endPtr, Player* playerPtr);

Tile moveCat(Tile* startPtr, Tile* endPtr, Cat* catPtr);

Tile moveCopyCat(Tile* start, Tile* end, CopyCat* copyCatPtr);

#endif

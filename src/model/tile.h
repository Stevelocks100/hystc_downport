#ifndef TILE_H
#define TILE_H

#include "player.h"
#include "cat.h"
#include "copycat.h"
#include "noisetrap.h"

//Tile
typedef enum {NORMAL, SAFE, WALL, NOISETRAP, PROP, DISPOSALBIN, TERMINAL, EXIT, ELEVATOR}TileType;
typedef struct {
    TileType type;
    Player *player;
    Cat *cat;
    CopyCat *copyCat;
    NoiseTrap trap;
}Tile;

Tile movePlayer(Tile* startPtr, Tile* endPtr, Player* playerPtr);

Tile moveCat(Tile* startPtr, Tile* endPtr, Cat* catPtr);

Tile moveCopyCat(Tile* start, Tile* end, CopyCat* copyCatPtr);

#endif

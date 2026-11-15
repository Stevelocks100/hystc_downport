#ifndef ROOM_H
#define ROOM_H

#include "tile.h"
#include "terminal.h"
#include "disposalbin.h"

/*Rooms are a 2D array of tiles*/
/*TODO implement 40x12 grid of tiles*/
typedef struct {
    Tile room[25][40];
    Terminal terminals[2];
    DisposalBin bin;
}Room;
#endif

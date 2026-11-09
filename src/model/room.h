#ifndef ROOM_H
#define ROOM_H

#include "tile.h"

/*Rooms are a 2D array of tiles*/
/*TODO implement 40x12 grid of tiles*/
typedef struct {
    Tile room[25][40];
}Room;
#endif

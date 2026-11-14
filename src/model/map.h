#ifndef MAP_H
#define MAP_H
#include "room.h"

typedef struct {
    Room rooms[5][5];
    int current_room;
}Map;
#endif

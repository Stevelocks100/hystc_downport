#ifndef CAT_H
#define CAT_H

#include "../include/globals.h"
#include "vec2.h"
#include <stdbool.h>
#include <stdlib.h>

typedef enum {/*TODO think of other traits*/
    FAT,
}Trait;

typedef struct {
    Vec2 mapCoords;
    Trait trait1;
    Trait trait2;
    bool shaking;
    bool found;
    bool moving;
    int moveTimer;
}Cat;

void wander(Cat *catPtr);

Vec2 follow(Vec2 nextPos, Cat *catPtr[CATS]);

#endif

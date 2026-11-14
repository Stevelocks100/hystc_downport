#ifndef CAT_H
#define CAT_H

#include "vec2.h"
#include <stdbool.h>

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
}Cat;

#endif

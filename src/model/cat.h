#include "trait.h"
#ifndef CAT_H
#define CAT_H

typedef struct {
    int position[10][10];
    enum Trait trait1;
    enum Trait trait2;
    bool shaking;
    bool found;
    bool moving;
}Cat;

#endif

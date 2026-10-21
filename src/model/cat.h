#include "trait.h"
#ifndef MODEL_H
#define MODEL_H

typedef struct {
    int position[10][10];
    enum Trait trait1;
    enum Trait trait2;
    bool shaking;
    bool found;
    bool moving;
}Cat;

void move(Cat cat, int positionX, int PositionY);

void setTraits(Cat cat, Trait trait1, Trait trait2);

bool isShaking(Cat cat);

void shakingToggle(Cat cat);

bool isFound(Cat cat);

bool foundToggle(Cat cat);

bool isMoving(Cat cat);

bool movingToggle(Cat cat);

#endif

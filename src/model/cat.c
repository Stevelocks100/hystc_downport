#include "cat.h"

void wander(Cat *catPtr) {
    
};

Vec2 follow(Vec2 nextPos, Cat *catPtr[CATS]) {
    int i = 0;
    Vec2 lastPos;
    while(i < CATS) {
        if(catPtr[i] == NULL || !catPtr[i]->found){
            i++;
            continue;
        } 
        lastPos.x = catPtr[i]->mapCoords.x;
        lastPos.y = catPtr[i]->mapCoords.y;
        catPtr[i]->mapCoords.x = nextPos.x;
        catPtr[i]->mapCoords.y = nextPos.y;
        nextPos.x = lastPos.x;
        nextPos.y = lastPos.y;
        i++;
    };
};
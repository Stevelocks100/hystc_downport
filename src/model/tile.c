#include "tile.h"
#include <stdlib.h>

Tile movePlayer(Tile* startPtr, Tile* endPtr, Player* playerPtr) {
    if((*endPtr).type == WALL) { /*does nothing if destination is a wall*/
        return *startPtr;   
    }else {
        (*startPtr).player = NULL;
        (*endPtr).player = playerPtr;
        if((*endPtr).type == NOISETRAP){
            /*TODO NOISETRAP CALL*/
        };
        return *endPtr;
    };
};

Tile moveCat(Tile* startPtr, Tile* endPtr, Cat* catPtr) {
    if((*endPtr).type == WALL) { /*does nothing if destination is a wall*/
        return *startPtr;   
    }else {
        (*startPtr).cat = NULL;
        (*endPtr).cat = catPtr;
        if((*endPtr).type == NOISETRAP){
            /*TODO NOISETRAP CALL*/
        };
        return *endPtr;
    };
};


Tile moveCopyCat(Tile* startPtr, Tile* endPtr, CopyCat* copyCatPtr) {
    if((*endPtr).type == WALL) { /*does nothing if destination is a wall*/
        return *startPtr;   
    }else {
        (*startPtr).copyCat = NULL;
        (*endPtr).copyCat = copyCatPtr;
        if((*endPtr).type == NOISETRAP){
            /*TODO NOISETRAP CALL*/
        };
        return *endPtr;
    };
};



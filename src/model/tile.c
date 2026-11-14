#include "tile.h"
#include <stdlib.h>

Tile* movePlayer(Tile* startPtr, char wasd, Player* playerPtr) {
    switch (wasd) {
        case 'w':
        case 'W':
            switch ((*playerPtr).direction) {
                case NORTH:
                    startPtr
                    break;
                case EAST:
                    break;
                case WEST:
                    break;
                case SOUTH:
                    break;
            };
            break;
        case 'a':
        case 'A':
            switch ((*playerPtr).direction) {
                case NORTH:
                    break;
                case EAST:
                    break;
                case WEST:
                    break;
                case SOUTH:
                    break;
            };
            break;
        case 'd':
        case 'D':
            switch ((*playerPtr).direction) {
                case NORTH:
                    break;
                case EAST:
                    break;
                case WEST:
                    break;
                case SOUTH:
                    break;
            };
            break;
        case 's':
        case 'S':
            switch ((*playerPtr).direction) {
                case NORTH:
                    break;
                case EAST:
                    break;
                case WEST:
                    break;
                case SOUTH:
                    break;
            };
            break;
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



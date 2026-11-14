#include <stdlib.h>
#include <stdbool.h>
#include "player.h"

/*receives moveVector, playerPtr, and roomPtr from asynch.movement_request()*/
void movePlayer(Vec2 moveVec, Player* playerPtr, Room* roomPtr){
    Vec2 destCoords = playerPtr->mapCoords;
    destCoords.x += moveVec.x;
    destCoords.y += moveVec.y;

    if( destCoords.x < 0 ||                                     /*out of bounds error handling*/
        destCoords.x >=(SCREEN_WIDTH/TILE_SIZE) || 
        destCoords.y < 0 || 
        destCoords.y >= (SCREEN_HEIGHT/TILE_SIZE))
        return;

    switch(roomPtr->room[destCoords.y][destCoords.x].type) {    /*checks for destination tile type*/
        case WALL:                                              /*no movement for wall*/
            break;                                              /*funny idea, what if running into a wall
                                                                  stunned you*/
        case NOISETRAP:
            /*TODO implement noisetrap call*/
        case SAFE:
            playerPtr->safe = true;
        case NORMAL:
        case PROP:
        case DISPOSALBIN:
        case TERMINAL:
        case ELEVATOR:
            playerPtr->mapCoords.x = destCoords.x;
            playerPtr->mapCoords.y = destCoords.y;
            break;
    };

};

void flashToggle(Player* player){
    (*player).flashlight = !(*player).flashlight;
}

void look(Player* player, Direction direction){
    (*player).direction = direction;
};
bool isSafe(Player* player, int positionX, int positionY) {

};

void setSpeed(Player* player, int newSpeed){
    (*player).speed = newSpeed;
};



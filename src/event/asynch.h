#ifndef ASYNCH_H
#define ASYNCH_H

#include "../include/globals.h"
#include "../input/input.h"
#include "../model/tile.h"
#include "../model/player.h"
#include "../model/staminabar.h"
#include "../model/vec2.h"

/*must be called after sprint_request*/
/*called every tick by game loop*/
/*player.moving must be set each tick depending on input*/
void movement_request();
void movement_request(Direction moveDir, Player* playerPtr, Room* roomPtr) {
    if(moveDir != playerPtr->lookDir)               /*reduces speed if movement penalty*/
        playerPtr->speed -= LOOKING_PENALTY;

    if(!playerPtr->moving)                          /*resets move_timer if not moving*/
        playerPtr->move_timer = playerPtr->speed;

    Vec2 moveVector;                                /*setting movement vector*/
    switch (moveDir) {
        case NORTH:
            moveVector.x = 0;
            moveVector.y = -1;
            break;
        case EAST:
            moveVector.x = 1;
            moveVector.y = 0;
            break;
        case WEST:
            moveVector.x = -1;
            moveVector.y = 0;
            break;
        case SOUTH:
            moveVector.x = 0;
            moveVector.y = -1;
            break;
    };

    if(moveDir != playerPtr->lastMoveDir) {         /*checks if still moving in same dir as last tick*/
        playerPtr->move_timer = playerPtr->speed;   /*otherwise resets move_timer*/
        playerPtr->lastMoveDir = moveDir;
    };

    if(playerPtr->move_timer == 0)                  /*if move_timer is done, moves player*/
        movePlayer(moveVector, playerPtr, roomPtr);
    return;

    playerPtr->move_timer -= 1;
    
};

#endif

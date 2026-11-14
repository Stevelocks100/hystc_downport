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
void movement_request(Direction moveDir, Player* playerPtr, Room* roomPtr);
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
/*check every tick for shift input in game loop*/
/*needs to be called before movement_request because it subtracts look penalty from player.speed*/
void sprint_request(Player *playerPtr);
void sprint_request(Player *playerPtr) {
    if(can_run(playerPtr->staminaBar))
        playerPtr->speed = SPRINT_SPEED;
    else
        playerPtr->speed = WALK_SPEED;
};


/*called in game loop if q depressed*/
void flashlight_toggle_request(Player *playerPtr);
void flashlight_toggle_request(Player *playerPtr){
    playerPtr->flashlight = !playerPtr->flashlight;
};

/*set catPtr = NULL in main game loop if no cat on tile*/
void interact_request(Player *playerPtr, Cat *catPtr, Room *roomPtr){
    if(catPtr != NULL) {
        catPtr->found = true;
        catPtr->moving = false;
    };
    return;

    switch(roomPtr->room[playerPtr->mapCoords.y][playerPtr->mapCoords.x].type){
        case DISPOSALBIN:
            /*TODO implement disposal bin*/
            break;
        case TERMINAL:
            /*TODO implement terminal puzzle*/
            break;
        };
};

void look_dir_request(Player *playerPtr, bool right);

void look_dir_request(Player *playerPtr, bool right) {
    switch (playerPtr->lookDir) {
        case NORTH:
            if (right) {
                playerPtr->lookDir = EAST;
            } else {
                playerPtr->lookDir = WEST;
            }
            break;
        case EAST:
            if (right)
            {
                playerPtr->lookDir = SOUTH;
            }
            else
            {
                playerPtr->lookDir = NORTH;
            }
            break;
        case SOUTH:
            if (right)
            {
                playerPtr->lookDir = WEST;
            }
            else
            {
                playerPtr->lookDir = EAST;
            }
            break;
        case WEST:
            if (right)
            {
                playerPtr->lookDir = NORTH;
            }
            else
            {
                playerPtr->lookDir = SOUTH;
            }
            break;
    };

};



#endif

#include <stdlib.h>
#include <stdbool.h>
#include "player.h"

void flashToggle(Player player){
    player.flashlight = !player.flashlight;
}

void look(Player player, Direction direction){
    player.direction = direction;
};
bool isSafe(Player player, int positionX, int positionY) {
    return false;
};

void turn(Player player, bool right) {
    /* right == false means left */

    switch (player.direction) {
        case NORTH:
            if (right) {
                player.direction = EAST;
            } else {
                player.direction = WEST;
            }
            break;
        case EAST:
            if (right)
            {
                player.direction = SOUTH;
            }
            else
            {
                player.direction = NORTH;
            }
            break;
        case SOUTH:
            if (right)
            {
                player.direction = WEST;
            }
            else
            {
                player.direction = EAST;
            }
            break;
        case WEST:
            if (right)
            {
                player.direction = NORTH;
            }
            else
            {
                player.direction = SOUTH;
            }
            break;
    }

}

void update_position(Player player, int positionX, int positionY) {
    /* move position, but check if there's a wall. */
    /* if player goes past boundary */
}

void move(Player player, int speed, )
{   
    int i;
    /* only move player by one, to prevent issues with clipping through walls*/
    for (i = 0; i < speed; i++) {

        switch (player.direction)
        {
        case NORTH:
            update_position(player, 0, 1);
            break;
        case EAST:
            update_position(player, 1, 0);
            break;
        case SOUTH:
            update_position(player, 0, -1);
            break;
        case WEST:
            update_position(player, -1, 0);
            break;
        }
    }
}

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

};

void setSpeed(Player player, int newSpeed){
    player.speed = newSpeed;
};



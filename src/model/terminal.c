#include "terminal.h"

void updateProgress(Terminal *terminalPtr) {
    terminalPtr->progress += TERM_SPEED;

    if(terminalPtr->progress >= TERM_INTERACT){
        toggleDoor(terminalPtr);
        terminalPtr->progress = 0;
    }

};

void toggleDoor(Terminal *terminalPtr) {
    if(terminalPtr->doors[0]->type == OPENDOOR)
        terminalPtr->doors[0]->type = CLOSEDDOOR;
    else
        terminalPtr->doors[1]->type = OPENDOOR;
}

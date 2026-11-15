#include "terminal.h"

void updateTermProgress(Terminal *terminalPtr) {
    terminalPtr->progress += TERM_SPEED;

    if(terminalPtr->progress >= TERM_INTERACT){
        toggleDoor(terminalPtr);
        terminalPtr->progress = 0;
    }

};

void toggleDoor(Terminal *terminalPtr) {
    if(terminalPtr->doors[0]->type == OPENDOOR)
        doorClose(terminalPtr);
    else
        doorOpen(terminalPtr);
};

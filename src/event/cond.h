#ifndef COND_H
#define COND_H

#include "../model/tile.h"
#include "../model/terminal.h"

void doorOpen(Terminal *terminalPtr);
void doorOpen(Terminal *terminalPtr) {
    terminalPtr->doors[0]->type = OPENDOOR;
    terminalPtr->doors[1]->type = OPENDOOR;
    /*TODO implement copycat behaviour*/
};

void doorClose(Terminal *terminalPtr);
void doorClose(Terminal *terminalPtr) {
    terminalPtr->doors[0]->type = CLOSEDDOOR;
    terminalPtr->doors[0]->type = CLOSEDDOOR;
    /*TODO implement copycat behaviour*/
};
#endif

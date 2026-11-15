#ifndef TERMINAL_H
#define TERMINAL_H

#include "../event/cond.h"
#include "tile.h"

typedef struct {
    int progress;
    Tile *doors[2]; /*terminal's associated door tiles*/
}Terminal;

void updateTermProgress(Terminal *terminalPtr);

void toggleDoor(Terminal *terminalPtr);
#endif

#ifndef TERMINAL_H
#define TERMINAL_H

#include "room.h"

typedef struct {
    int progress;
    Tile *doors[2]; /*terminal's associated door tiles*/
}Terminal;

void updateProgress(Terminal *terminalPtr);

void toggleDoor(Terminal *terminalPtr);
#endif

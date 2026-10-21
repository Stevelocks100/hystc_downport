#include <stdbool.h>
#include <stdint.h>
#include "trait.h"
#ifndef MODEL_H
#define MODEL_H





typedef struct {
    bool open;
}DisposalBin;

typedef struct {
    //properties uncertain
}Terminal;

typedef struct {
    bool open;
}Door;

typedef struct {
    int col1;
    int col2;
    int col3;
}TerminalPuzzle;

typedef struct {
    bool visible;
}GameOver;

typedef struct {
    int type;
}NoiseTrap;

typedef struct {
    int stamina;
    int staminaTotal;
    int position[2];
    int size;
}StaminaBar;

typedef struct {
    Player player;
    Cat cats[5];
    CopyCat copycat;
    DisposalBin disposal;
    Door bunkerDoor;
    Terminal terminal;
    GameOver endScr;
    NoiseTrap traps[10]; //PROBABLY CHANGE THIS VALUE AT SOME POINT
    StaminaBar stamBar;
}Model;

#endif

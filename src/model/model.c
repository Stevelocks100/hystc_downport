#include <stdbool.h>
#include <stdint.h>
#include "trait.h"
typedef struct Player {
    int positionX;
    int positionY;
    bool flashlight;
    uint8_t direction; 
    bool safe;
    int speed;
}Player;

typedef struct Cat {
    int positionX;
    int positionY;
    enum Trait trait1;
    enum Trait trait2;
    bool shaking;
    bool found;
    bool moving;
}Cat;

typedef struct CopyCat {
    int positionX;
    int positionY;
    int state;
    bool moving;
    bool caught;
    bool render;
}CopyCat;

typedef struct DisposalBin {
    bool open;
}DisposalBin;

typedef struct Terminal {
    //properties uncertain
}Terminal;

typedef struct Door {
    bool open;
}Door;

typedef struct TerminalPuzzle {
    int col1;
    int col2;
    int col3;
    //how to implement correct answer? no tuples in C, and arrays seem suboptimal
}TerminalPuzzle;

typedef struct GameOver {
    bool visible;
}GameOver;

typedef struct NoiseTrap {
    int type;
}NoiseTrap;

typedef struct StaminaBar {
    int stamina;
    int staminaTotal;
    int positionX;
    int positionY;
    int size;
}StaminaBar;

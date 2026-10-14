#include <stdbool.h>
#include <stdint.h>
#include "trait.h"
struct Player {
    int positionX;
    int positionY;
    bool flashlight;
    uint8_t direction; 
    bool safe;
    int speed;
};

struct Cat {
    int positionX;
    int positionY;
    enum Trait trait1;
    enum Trait trait2;
    bool shaking;
    bool found;
    bool moving;
};

struct CopyCat {
    int positionX;
    int positionY;
    int state;
    bool moving;
    bool caught;
    bool render;
};

struct DisposalBin {
    bool open;
};

struct Terminal {
    //properties uncertain
};

struct Door {
    bool open;
};

struct TerminalPuzzle {
    int col1;
    int col2;
    int col3;
    //how to implement correct answer? no tuples in C, and arrays seem suboptimal
};

struct GameOver {
    bool visible;
};

struct NoiseTrap {
    int type;
};

struct StaminaBar {
    int stamina;
    int staminaTotal;
    int positionX;
    int positionY;
    int size;

};

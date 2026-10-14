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
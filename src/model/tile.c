#include <stdbool.h>
#include "tile.h"

bool hasPlayer(Tile tile){
    return tile.player;
};

void togglePlayer(Tile tile){
    tile.player = !tile.player;
};

bool hasCat(Tile tile){
    return tile.cat;
};

void toggleCat(Tile tile) {
    tile.cat = !tile.cat;
};

bool hasCopyCat(Tile tile) {
    return tile.copyCat;
};

void toggleCopyCat(Tile tile) {
    tile.copyCat = !tile.copyCat;
};

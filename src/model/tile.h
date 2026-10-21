#ifndef TILE_H
#define TILE_H


//Tile
typedef enum {NORMAL, SAFE, WALL, NOISETRAP, PROP, DISPOSALBIN, TERMINAL, EXIT, ELEVATOR}TileType;
typedef struct {
    int positionX;
    int positionY;
    TileType type;
    bool player;
    bool cat;
    bool copyCat;
}Tile;

bool hasPlayer(Tile tile);

void togglePlayer(Tile tile);

bool hasCat(Tile tile);

void toggleCat(Tile tile);

bool hasCopyCat(Tile tile);

void toggleCopyCat(Tile tile);
#endif

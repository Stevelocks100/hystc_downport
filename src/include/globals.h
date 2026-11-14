#ifndef GLOBALS_H
#define GLOBALS_H

#define BYTES_PER_SCREEN 32000
#define LONG_PER_SCREEN 8000

#define SCREEN_WIDTH_BYTES 80
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define MAP_WIDTH 40
#define MAP_HEIGHT 25
#define TILE_SIZE 16

#define SPRINT_SPEED 2
#define WALK_SPEED 1

#define ROOM_SIZE 9

#define LOOKING_PENALTY 1

int abs(int x);
int abs(int x) {
    if (x < 0) {
        return -x;
    }
}

#endif

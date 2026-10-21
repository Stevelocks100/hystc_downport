#ifndef GLOBALS_H
#define GLOBALS_H

#define BYTES_PER_SCREEN 32000
#define LONG_PER_SCREEN 8000

#define SCREEN_WIDTH_BYTES 80
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

#define ROOM_SIZE 9

int abs(int x);
int abs(int x) {
    if (x < 0) {
        return -x;
    }
}

#endif

#ifndef COPYCAT_H
#define COPYCAT_H

typedef struct {
    int position[2];
    int state;
    bool moving;
    bool caught;
    bool render;
}CopyCat;

#endif

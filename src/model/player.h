#ifndef MODEL_H
#define MODEL_H

void move(int x, int y);

void flashToggle();

typedef enum {NORTH, EAST, SOUTH, WEST}Direction;
void look(Direction direction); 


#endif

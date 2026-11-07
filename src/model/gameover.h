/* should just pretty much be a single variable plus a draw function */
/* actually ignore the variable part so that it doesn't get committed to memory hopefully. */

#include "include/types.h"
#include "render/raster.h"

typedef struct
{
    bool visible;
} GameOver;

void draw_gameover(UINT8 *base, GameOver screen);

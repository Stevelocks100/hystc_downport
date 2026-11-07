#include "gameover.h"
#include "include/globals.h"

void draw_gameover(UINT8 *base, UINT8 *font, GameOver screen) {
    /* on second thought, it should be procedurally generated.*/
    /* first, just do horizontal lines across the screen. */
    int i;


    if (!screen.visible) {
        return;
    }

    for (i = 0; i < SCREEN_HEIGHT; i += 2) {
        plot_horizontal_line(base, i, 0, SCREEN_WIDTH)''
    }

    /* afterwards, clear the approximate center. 177 x 155. region is 286 x 90 */

    clear_region(base, 155, 177, 286, 90);
    plot_string(base, font, 155+20,177+20, 'NO SIGNAL');
    /* determine the string pos later. */
}


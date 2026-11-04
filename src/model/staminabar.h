#ifndef STAMINABAR_H
#define STAMINABAR_H

#include "render/raster.h"
#include "include/types.h"
#include "math.h"

/* math needed for min/max */

/* for simplicity, position is the top left. */
/* should be drawn as a regular rectangle, with black surrounding it (using clear region as interior) */

/* size is now height, and width is determined from stamina total. */
/* this means that less calculations are required to render the stamina bar.*/
/* cooldown now exists, as a slight delay before actually regenerating. */

typedef struct
{
    int stamina;
    int staminaTotal;
    int position[2];
    int height;
    int cooldown;
} StaminaBar;

void draw_stamina_bar(UINT8 *base, StaminaBar stamBar);

void draw_stamina_bar(UINT8 *base, StaminaBar stamBar) {
    plot_rectangle(base, stamBar.position[0], stamBar.position[1], stamBar.staminaTotal + 2, stamBar.height + 2);

    if (stamBar.stamina > 0) {
        clear_region(base, stamBar.position[0] + 1, stamBar.position[1] + 1, stamBar.stamina, stamBar.height);
    }
}

void init(StaminaBar stamBar);

void init(StaminaBar stamBar) {
    /* to fill the variables */
    stamBar.stamina = 100;
    stamBar.staminaTotal = 100;
    stamBar.position = [0,0];
    stamBar.height = 5;
    stamBar.cooldown = 0;
}
void tick(bool active, StaminaBar stamBar);

void tick(bool active, StaminaBar stamBar) {
    if (active) {
        stamBar.cooldown = 70;
        /* assuming it's 70 ticks per second (TPS) */
        stamBar.stamina = max(0, stamBar.stamina-1);

    } else {
        if (stamBar.cooldown > 1) {
            stamBar.cooldown--;
            /* don't do anything with stamina. */

        } else {
            /* regen stamina. */
            stamBar.stamina = min(stamBar.staminaTotal, stamBar.stamina+1);
        }
    }
}

#endif
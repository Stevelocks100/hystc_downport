#ifndef STAMINABAR_H
#define STAMINABAR_H

#include "render/raster.h"
#include "include/types.h"
#include "math.h"
#include <stdbool.h>

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

/* hypothetically, function overrides exist. */

void draw_staminabar(UINT8 *base, StaminaBar stamBar);

void init_staminabar(StaminaBar stamBar);

void tick_staminabar(StaminaBar stamBar, bool active);

bool can_run(StaminaBar stamBar);

#endif
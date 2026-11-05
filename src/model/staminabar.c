#include "staminabar.h"


void draw_staminabar(UINT8 *base, StaminaBar stamBar)
{
    plot_rectangle(base, stamBar.position[0], stamBar.position[1], stamBar.staminaTotal + 2, stamBar.height + 2);

    if (stamBar.stamina > 0)
    {
        clear_region(base, stamBar.position[0] + 1, stamBar.position[1] + 1, stamBar.stamina, stamBar.height);
    }
}

void init_staminabar(StaminaBar stamBar)
{
    /* to fill the variables */
    stamBar.stamina = 100;
    stamBar.staminaTotal = 100;
    stamBar.position = [ 0, 0 ];
    stamBar.height = 5;
    stamBar.cooldown = 0;
}

void tick_staminabar(StaminaBar stamBar, bool active)
{
    if (active)
    {
        stamBar.cooldown = 70;
        /* assuming it's 70 ticks per second (TPS) */
        stamBar.stamina = max(0, stamBar.stamina - 1);
    }
    else
    {
        if (stamBar.cooldown > 1)
        {
            stamBar.cooldown--;
            /* don't do anything with stamina. */
        }
        else
        {
            /* regen stamina. */
            stamBar.stamina = min(stamBar.staminaTotal, stamBar.stamina + 1);
        }
    }
}

bool can_run(StaminaBar stamBar) {
    return stamBar.stamina > 0;
}

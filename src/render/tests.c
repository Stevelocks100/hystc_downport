#include "raster.h"
#include "../include/types.h"
#include "../include/globals.h"

#include <linea.h>
#include <osbind.h>
#include <stdio.h>

int main() {
    UINT8 *base = Physbase();
    UINT8 *font;
    char ch;

    linea0();
    font = (char *)V_FNT_AD;

    clear_screen(base);
    ch = Cnecin();
    plot_pixel(base, 5, 50);
    plot_pixel(base, 6, 51);
    plot_rectangle(base, 50,100,50,80);
    
    ch = Cnecin();
    clear_region(base, 50, 100, 25, 25);
    ch = Cnecin();
    plot_horizontal_line(base,300,20,57);

    plot_horizontal_line(base, 330, 50, 57);
    ch = Cnecin();
    plot_vertical_line(base, 230, 50, 107);
    ch = Cnecin();
    plot_line(base,200,140, 100, 250);
    plot_line(base, 300, 140, 350, 250);
    plot_line(base, 100, 110, 190, 150);
    ch = Cnecin();

    return 0;
}
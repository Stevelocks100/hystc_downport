#ifndef RASTER_H
#define RASTER_H

/* TODO: clamp everything to not go past screen bounds. */

#include "stdio.h"
#include "osbind.h"
#include "types.h"
#include "globals.h"

/*----- Function: clear_screen -----
v
 PURPOSE: Clears the entire screen.

 INPUT: Address(UINT32*): to the start of the screen

 OUTPUT: None

*/
void clear_screen(UINT32 *base);

void clear_screen(UINT32 *base)
{
    printf("\033E\033f\n"); /* blank the screen */
}

/*----- Function: clear_region -----

 PURPOSE: Clear a region of the screen. The section is specified by the coordinates of the top left corner, and the height and width of the region.

 INPUT: Address(UINT32*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the region
        Length: the lenth (number of rows) in pixels of the region
        Width: the width (number of columns) in pixels of the region

 OUTPUT: None

*/
void clear_region(UINT32 *base, int row, int col, UINT16 length, UINT16 width);

void clear_region(UINT32 *base, int row, int col, UINT16 length, UINT16 width)
{
    if (length == 0 || width == 0) return; /* if the size happens to be 0, don't make it do anything */
    int byte1 = col >> 3;
    int byte2 = (col + width - 1) >> 3; /* first/last byte */

    int bit1 = col & 7;
    int bit2 = (col + width - 1) & 7; /* first/last bit */

    UINT8 mask;

    int i;
    int j; /* loop vars */

    for (i = row; i < row + length; i++) {
        for (j = byte1; j <= byte2; j++) {
            if (byte1 == byte2) {
                mask = (UINT8)((0xFF >> bit1) & (0xFF << (7 - bit2)));
                *(base + i * SCREEN_WIDTH_BYTES + j) &= (UINT8)~mask;
            } else if (j == byte1) {
                mask = (UINT8)(0xFF >> bit1);
                *(base + i * SCREEN_WIDTH_BYTES + j) &= (UINT8)~mask;
            } else if (j == byte2) {
                mask = (UINT8)(0xFF << (7 - bit2));
                *(base + i * SCREEN_WIDTH_BYTES + j) &= (UINT8)~mask;
            } else {
                *(base + i * SCREEN_WIDTH_BYTES + j) = 0;
            }
            
            /* essentially if it's an edge byte, do NOT wipe the whole thing. */
            /* accomplish this by cutting bits off a UINT8 then doing inverse of that */
        }
    }
}
/*----- Function: plot_pixel -----

 PURPOSE: Plots a single pixel on the screen.

 INPUT: Address(UINT8*): to the start of the screen
        Position(row,col): the location of the pixel to plot

 OUTPUT: None

*/
void plot_pixel(UINT8 *base, int row, int col);

void plot_pixel(UINT8 *base, int row, int col)
{
    if (col >= 0 && col < SCREEN_WIDTH && row >= 0 && row < SCREEN_HEIGHT)
        *(base + row * SCREEN_WIDTH_BYTES + (col >> 3)) |= 1 << (7 - (col & 7));
    /* this code is from an earlier tutorial or lecture */
}


/*----- Function: plot_horizontal_line -----

 PURPOSE: Plot a hoizontal line on the screen. The horizontal line is specified by the leftmost pixel of the line and the length of the line.

 INPUT: Address(UINT32*): to the start of the screen
        Position(row,col): the coordinates of the leftmost pixel of the horizontal line
        Length: the lenth in pixels of the line

 OUTPUT: None
*/
void plot_horizontal_line(UINT32 *base, int row, int col, UINT16 length);

void plot_horizontal_line(UINT32 *base, int row, int col, UINT16 length)
{
    if (length == 0) return; /* if the size happens to be 0, don't make it do anything */
    int byte1 = col >> 3;
    int byte2 = (col + width - 1) >> 3; /* first/last byte */

    int bit1 = col & 7;
    int bit2 = (col + width - 1) & 7; /* first/last bit */

    UINT8 mask;

    int j; /* loop vars */

    /* it's basically the same as clear region, except that it will be doing it for one row. */

    for (j = byte1; j <= byte2; j++)
    {
        if (byte1 == byte2)
        {
            mask = (UINT8)((0xFF >> bit1) & (0xFF << (7 - bit2)));
            *(base + row *SCREEN_WIDTH_BYTES + j) |= (UINT8)mask;
        }
        else if (j == byte1)
        {
            mask = (UINT8)(0xFF >> bit1);
            *(base + row * SCREEN_WIDTH_BYTES + j) |= (UINT8)mask;
        }
        else if (j == byte2)
        {
            mask = (UINT8)(0xFF << (7 - bit2));
            *(base + row * SCREEN_WIDTH_BYTES + j) |= (UINT8)mask;
        }
        else
        {
            *(base + row * SCREEN_WIDTH_BYTES + j) = -1; /* -1 is the equivalent of 0xFF for however large the data size is. */
        }

        /* essentially if it's an edge byte, do NOT wipe the whole thing. */
        /* accomplish this by cutting bits off a UINT8 */
    }

}


/*----- Function: plot_vertical_line -----

 PURPOSE: Plot a vertical line on the screen. The vertical line is specified by the topmost pixel of the line and the length of the line.

 INPUT: Address(UINT32*): to the start of the screen
        Position(row,col): the coordinates of the topmost pixel of the vertical line
        Length: the lenth in pixels of the line

 OUTPUT: None
*/
void plot_vertical_line(UINT32 *base, int row, int col, UINT16 length);

void plot_vertical_line(UINT32 *base, int row, int col, UINT16 length)
{
    int i;
    for (i = 0; i < length; i++) {
        plot_pixel(base, row + i, col);
    }
    /* there probably isn't a more efficient way to draw a line tbh */
    /* given that you can't just fully colour entire bytes. */
}

/*----- Function: plot_line -----

 PURPOSE: Plots a line on the screen between the two given points.

 INPUT: Address(UINT32*): to the start of the screen
        Position(start_row,start_col): the coordinates of the start of the line
        Position(end_row,end_col): the coordinates of the end of the line

 OUTPUT: None
*/
void plot_line(UINT32 *base, int start_row, int start_col, int end_row, int end_col);
/* go implement Bresenham’s Line Algorithm for this. */

void plot_line(UINT32 *base, int start_row, int start_col, int end_row, int end_col)
{

    /* calculate deltas (x1 - x0), for both X and Y */
    int dx = abs(end_col - start_col);
    int dy = abs(end_row - start_row);

    /* don't do some fancy algorithm when you can simplify straight lines */
    if (dx == 0) {
        plot_vertical_line(base, start_row, start_col, dy);
        return;
    }
    if (dy == 0) {
        plot_horizontal_line(base, start_row, start_col, dx);
        return;
    }

    /* to account for if start is larger than end. */
    int sx = (start_col < end_col) ? 1 : -1;
    int sy = (start_row < end_row) ? 1 : -1;

    /* create decision parameter, p = 2dy - x*/
    int p;

    int x = start_col;
    int y = start_row;


    if (dx >= dy) {
        p = (dy<<1) - dx;
        /* step through X, from x0 to x1 */
        for (x = start_col; x < end_col; x+=sx) {
            /* plot pixel at x,y */
            plot_pixel(base, y, x);

            /* if p < 0, p = p + 2dy */
            /* ^^ don't change the Y */
            if (p < 0) {
                p += dy<<1;
            } else {
                /* if p ≥ 0, p = p + 2dy - 2dx*/
                /* add 1 to y. */
                p += (dy<<1) - (dx<<1);
                y += sy;
            }

            /* increment X by 1. */
            /* ^^ in loop */

        }
    } else {
        /* given that normally this is good for mainly horizontal lines, this allows for vertical to also work. */
        /* step through Y, from y0 to y1 */
        p = (dx << 1) - dy;
        for (y = start_row; y < end_row; y += sy)
        {

            plot_pixel(base, y, x);


            if (p < 0)
            {
                p += dx << 1;
            }
            else
            {
                p += (dx << 1) - (dy << 1);
                x += sx;
            }
        }
    }
}

/*----- Function: plot_rectangle -----

 PURPOSE: Plots a rectangle on the screen given by the top left pixel, and the length and width of the rectangle.

 INPUT: Address(UINT32*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the rectangle
        Length: the lenth (number of rows) in pixels of the rectangle
        Width: the width (number of columns) in pixels of the rectangle

 OUTPUT: None
*/
void plot_rectangle(UINT32 *base, int row, int col, UINT16 length, UINT16 width);
/* should be the opposite of clear_region. */

void plot_rectangle(UINT32 *base, int row, int col, UINT16 length, UINT16 width)
{
    if (length == 0 || width == 0)
        return; /* if the size happens to be 0, don't make it do anything */
        
    int byte1 = col >> 3;
    int byte2 = (col + width - 1) >> 3; /* first/last byte */

    int bit1 = col & 7;
    int bit2 = (col + width - 1) & 7; /* first/last bit */

    UINT8 mask;

    int i;
    int j; /* loop vars */

    for (i = row; i < row + length; i++)
    {
        for (j = byte1; j <= byte2; j++)
        {
            if (byte1 == byte2)
            {
                mask = (UINT8)((0xFF >> bit1) & (0xFF << (7 - bit2)));
                *(base + i * SCREEN_WIDTH_BYTES + j) |= (UINT8)mask;
            }
            else if (j == byte1)
            {
                mask = (UINT8)(0xFF >> bit1);
                *(base + i * SCREEN_WIDTH_BYTES + j) |= (UINT8)mask;
            }
            else if (j == byte2)
            {
                mask = (UINT8)(0xFF << (7 - bit2));
                *(base + i * SCREEN_WIDTH_BYTES + j) |= (UINT8)mask;
            }
            else
            {
                *(base + i * SCREEN_WIDTH_BYTES + j) = -1;
            }

            /* essentially if it's an edge byte, do NOT wipe the whole thing. */
            /* accomplish this by cutting bits off a UINT8 then doing inverse of that */
        }
    }
}



/*----- Function: plot_square -----

 PURPOSE: Plots a square on the screen given by the top left pixel, and the length of the sides of the square.

 INPUT: Address(UINT32*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the square
        Side: the lenth of each side, in pixels, of the square

 OUTPUT: None
*/
void plot_square(UINT32 *base, int row, int col, UINT16 side);
/* should be pretty much equivalent to plot rect. probably could reuse the entire function */
void plot_square(UINT32 *base, int row, int col, UINT16 side) 
{
    plot_rectangle(base, row, col, side, side);
}

/*----- Function: plot_triangle -----

 PURPOSE: Plots a triangle on the screen given by the coordinate of the 90° angle, the length of the base, the length of the height, and the direction of the triangle.

 INPUT: Address(UINT32*): to the start of the screen
        Position(row,col): the coordinates of the pixel of the 90° angle of the triangle
        Base: the length (number of columns) of the base in pixels of the triangle
        Height: the lenth (number of rows) of the height in pixels of the triangle
        Direction: Describes where the coordinate is relative to the rest of the triangle
              0 - Coordinate is the top left point of the triangle
              1 - Coordinate is the top right point of the triangle
              2 - Coordinate is the bottom left point of the triangle
              3 - Coordinate is the bottom right point of the triangle


 OUTPUT: None
*/
void plot_triangle(UINT32 *base, int row, int col, UINT16 triangle_base, UINT16 height, UINT8 direction);

void plot_triangle(UINT32 *base, int row, int col, UINT16 triangle_base, UINT16 height, UINT8 direction)
{

    if (triangle_base == 0 || height == 0) return;

    /* for myself to comprehend the triangles:
     * 0 = |‾/
     * 1 = \‾|
     * 2 = |_\
     * 3 = /_|
     */
    /* determine direction of triangle. */
    /* based on this, calculate M (slope) */
    /* using M, that is now the length for the triangles */
    /* ^^ yeah this would be division, but it isn't used per-pixel. */
    
    /* length = x */
    /* height = y */
    /* not calculating slope here because it could be 0 which is a big problem */
    int i;
    int tri_len; /* triangle_length */

    int draw_col,draw_row;
    switch (direction) {
        case 0:
            for (i = 0; i <= height; i++) 
            {
                tri_len = triangle_base - (i * triangle_base) / height;
                if (tri_len < 1)
                    tri_len = 1;

                draw_row = row + i;
                draw_col = col;

                plot_horizontal_line(base, draw_row, draw_col, tri_len);
            }
            return;
        case 1:
            for (i = 0; i <= height; i++)
            {
                tri_len = (i * triangle_base) / height;
                if (tri_len < 1)
                    tri_len = 1;

                draw_row = row + i;
                draw_col = col - tri_len + 1;

                plot_horizontal_line(base, draw_row, draw_col, tri_len);
            }
            return;
        case 2:
            for (i = 0; i <= height; i++)
            {
                tri_len = (i * triangle_base) / height;
                if (tri_len < 1)
                    tri_len = 1;

                draw_row = row - height + i;
                draw_col = col;

                plot_horizontal_line(base, draw_row, draw_col, tri_len);
            }
            return;
        case 3:
            for (i = 0; i <= height; i++)
            {
                tri_len = triangle_base - (i * triangle_base) / height;
                if (tri_len < 1)
                    tri_len = 1;

                draw_row = row - height + i;
                draw_col = col - tri_len + 1;

                plot_horizontal_line(base, draw_row, draw_col, tri_len);
            }
            return;
        default:
            return;
    }
}
/*----- Function: plot_8bit_bitmap -----

 PURPOSE: Plots a bitmap to the screen given by the top left pixel of the bitmap and the height of bitmap.

 INPUT: Address(UINT8*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the bitmap
        Height: the lenth (number of rows) of the height in pixels of the bitmap

 OUTPUT: None
*/
void plot_8bit_bitmap(UINT8 *base, int row, int col, const UINT8 *bitmap, UINT16 height);


/*----- Function: plot_16bit_bitmap -----

 PURPOSE: Plots a bitmap to the screen given by the top left pixel of the bitmap and the height of bitmap.

 INPUT: Address(UINT16*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the bitmap
        Height: the lenth (number of rows) of the height in pixels of the bitmap

 OUTPUT: None
*/
void plot_16bit_bitmap(UINT16 *base, int row, int col, const UINT16 *bitmap, UINT16 height);


/*----- Function: plot_32bit_bitmap -----

 PURPOSE: Plots a bitmap to the screen given by the top left pixel of the bitmap and the height of bitmap.

 INPUT: Address(UINT32*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the bitmap
        Height: the lenth (number of rows) of the height in pixels of the bitmap

 OUTPUT: None
*/
void plot_32bit_bitmap(UINT32 *base, int row, int col, const UINT32 *bitmap, UINT16 height);


/*----- Function: plot_character -----

 PURPOSE: Plots a single character, as a bitmap from a font table, to the screen.

 INPUT: Address(UINT8*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the character
        ch(char): the character to be written to the screen

 OUTPUT: None
*/
void plot_character(UINT8 *base, int row, int col, char ch);


/*----- Function: plot_string -----

 PURPOSE: Plots a string, as a sequence of bitmaps from a font table, to the screen.

 INPUT: Address(UINT8*): to the start of the screen
        Position(row,col): the coordinates of the top left pixel of the string
        ch(c-string): the string to be written to the screen

 OUTPUT: None
*/
void plot_string(UINT8 *base, int row, int col, char *ch);

#endif

#include "input.h"

bool has_input() {/*Returns a byte of ascii info*/
    return Cconis();
};

long get_input(){/*Returns a longword of of key info: ascii value in bits 0-7, hardware scan code in bits 16-23, shift key state in bits 24-31*/
    return Crawcin();
};

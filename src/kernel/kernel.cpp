#include "io/print.h"

extern "C" void kernel_main(void) 
{
	nk_screen_clear();
    nk_print_setColor(NK_PRINT_COLOR_YELLOW, NK_PRINT_COLOR_BLACK);
    nk_print_str("Welcome to Neo kernel!\n");
}
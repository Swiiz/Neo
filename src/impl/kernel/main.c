#include "print.h"

void kernel_main() {
    screen_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to Neo kernel!");
}
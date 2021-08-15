#pragma once

#include <stdint.h>
#include <stddef.h>

enum {
    NK_PRINT_COLOR_BLACK = 0,
    NK_PRINT_COLOR_BLUE = 1,
    NK_PRINT_COLOR_GREEN = 2,
    NK_PRINT_COLOR_CYAN = 3,
    NK_PRINT_COLOR_RED = 4,
    NK_PRINT_COLOR_MAGENTA = 5,
    NK_PRINT_COLOR_BROWN = 6,
    NK_PRINT_COLOR_LIGHT_GRAY = 7,
    NK_PRINT_COLOR_DARK_GRAY = 8,
    NK_PRINT_COLOR_LIGHT_BLUE = 9,
    NK_PRINT_COLOR_LIGHT_GREEN = 10,
    NK_PRINT_COLOR_LIGHT_CYAN = 11,
    NK_PRINT_COLOR_LIGHT_RED = 12,
    NK_PRINT_COLOR_PINK = 13,
    NK_PRINT_COLOR_YELLOW = 14,
    NK_PRINT_COLOR_WHITE = 15
};
/**
 * Transform an integer into a string
 * @param val value
 * @param base desired base
 * @return string
 */
const char* nk_itoa(int val, int base);

/**
 * Print a char in vga text mode
 * @param character
 */
void nk_print_char(char character);
/**
 * Jump a line in vga text mode
 */
void nk_print_endl();
/**
 * Print a string in vga text mode
 * @param string
 */
void nk_print_str(const char *string);
/**
 * Print an integer in the disered base in vga text mode
 * @param val
 * @param base
 */
void nk_print_intB(int val, int base);
/**
 * Print an integer in base 10 in vga text mode
 * @param val
 */
void nk_print_int(int val);
/**
 * Print an integer as hexidecimal in vga text mode
 * @param val
 */
void nk_print_hex(int val);

/**
 * Clear the desired row ion vga text mode
 * @param row
 */
void nk_screen_clearRow(size_t row);
/**
 * Clear the entire screen in vga text mode
 */
void nk_screen_clear();

/**
 * Set the background color in vga text mode (see: NK_PRINT_COLOR_*)
 * @param background
 */
void nk_print_setBg(uint8_t background);
/**
 * Set the foreground color in vga text mode (see: NK_PRINT_COLOR_*)
 * @param background
 */
void nk_print_setFg(uint8_t foreground);
/**
 * Set the background and background color in vga text mode (see: NK_PRINT_COLOR_*)
 * @param background
 */
void nk_print_setColor(uint8_t foreground, uint8_t background);
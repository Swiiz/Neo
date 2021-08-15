#pragma once

#include <stdint.h>
#include <stddef.h>

namespace neo::kernel::print {
    enum Color {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHT_GRAY = 7,
        DARK_GRAY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        PINK = 13,
        YELLOW = 14,
        WHITE = 15
    };

    /**
     * Transform an integer into a string
     * @param val value
     * @param base desired base
     * @return string
     */
    const char* itoa(int val, int base);

    /**
     * Print a char in vga text mode
     * @param character
     */
    void printChar(char character);
    constexpr auto printchar = printChar;
    /**
     * Jump a line in vga text mode
     */
    void nextLine();
    constexpr auto printendl = nextLine;
    /**
     * Print a string in vga text mode
     * @param string
     */
    void printString(const char *string);
    constexpr auto printstr = printString;
    /**
     * Print an integer in the disered base in vga text mode
     * @param val
     * @param base
     */
    void printInteger(int val, int base);
    /**
     * Print an integer in base 10 in vga text mode
     * @param val
     */
    void printInteger(int val);
    /**
     * Print an integer as hexidecimal in vga text mode
     * @param val
     */
    void printHex(int val);

    /**
     * Set the background color in vga text mode (see: NK_PRINT_COLOR_*)
     * @param background
     */
    void setBackground(uint8_t background);
    /**
     * Set the foreground color in vga text mode (see: NK_PRINT_COLOR_*)
     * @param background
     */
    void setForeground(uint8_t foreground);
    /**
     * Set the background and background color in vga text mode (see: NK_PRINT_COLOR_*)
     * @param background
     */
    void setColor(uint8_t foreground, uint8_t background);

    namespace screen {
        /**
         * Clear the desired row ion vga text mode
         * @param row
         */
        void clearRow(size_t row);
        /**
         * Clear the entire screen in vga text mode
         */
        void clear();
    }
}
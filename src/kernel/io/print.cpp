#include "print.h"

namespace neo::kernel::print {
    const static size_t NUM_COLS = 80;
    const static size_t NUM_ROWS = 25;

    struct TChar {
        uint8_t character;
        uint8_t color;
    };

    struct TChar* buffer = (struct TChar*) 0xb8000;
    size_t y, x;
    uint8_t color = print::Color::WHITE | print::Color::BLACK << 4;

    const char* itoa(int val, int base) {
        static char buf[32] = {0};
        int i = 30;
        for(; val && i ; --i, val /= base)
            buf[i] = "0123456789abcdefghijklmnopqrstuvwxyz"[val % base];
        return &buf[i+1];
    }

    void printInteger(int val, int base) {
        printString(itoa(val, base));
    }

    void printInteger(int val) {
        printInteger(val, 10);
    }

    void printHex(int val) {
        printInteger(val, 16);
    }

    void printString(const char *string) {
        for (size_t i = 0; 1; ++i) {
            char character = (uint8_t) string[i];
            if(!character) return;
            printChar(character);
        }
    }

    void nextLine() {
        x = 0;

        if(y < NUM_ROWS - 1) {
            y++;
            return;
        }

        for(size_t r = 1; r < NUM_ROWS; r++) {
            for(size_t c = 0; c < NUM_COLS; c++) {
                TChar character = buffer[c + NUM_COLS * r];
                buffer[c + NUM_COLS * (r - 1)] = character;
            }
        }
        screen::clearRow(NUM_COLS - 1);
    }

    void printChar(char character) {
        if(character == '\n') {
            nextLine();
            return;
        }

        if(x > NUM_COLS) nextLine();

        buffer[x + NUM_COLS * y] = {(uint8_t) character, color};

        x++;
    }

    void setColor(uint8_t foreground, uint8_t background) {
        color = foreground + (background << 4);
    }

    void setBackground(uint8_t background) {
        color += (background << 4);
    }

    void setForeground(uint8_t foreground) {
        color += foreground;
    }

    namespace screen {
        void clearRow(size_t row) {
            struct TChar empty{' ', color};

            for (size_t i = 0; i < NUM_COLS; ++i) {
                buffer[i + NUM_COLS * row] = empty;
            }
        }

        void clear() {
            for (size_t i = 0; i < NUM_ROWS; ++i) {
                clearRow(i);
            }
        }
    }
}
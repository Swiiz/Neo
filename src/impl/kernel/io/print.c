#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct VGA_Char {
    uint8_t character;
    uint8_t color;
};

struct VGA_Char* buffer = (struct VGA_Char*) 0xb8000;
size_t y, x;
uint8_t color = NK_PRINT_COLOR_WHITE | NK_PRINT_COLOR_BLACK << 4;

const char* nk_itoa(int val, int base) {
    static char buf[32] = {0};
    int i = 30;
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789abcdefghijklmnopqrstuvwxyz"[val % base];
    return &buf[i+1];
}

void nk_print_intB(int val, int base) {
    nk_print_str(nk_itoa(val, base));
}

void nk_print_int(int val) {
    nk_print_intB(val, 10);
}

void nk_print_hex(int val) {
    nk_print_intB(val, 16);
}


void nk_print_str(const char *string) {
    for (size_t i = 0; 1; ++i) {
        char character = (uint8_t) string[i];
        if(!character) return;
        nk_print_char(character);
    }
}

void nk_screen_clearRow(size_t row) {
    struct VGA_Char empty = (struct VGA_Char) {
        .character =  ' ',
        .color = color
    };

    for (size_t i = 0; i < NUM_COLS; ++i) {
        buffer[i + NUM_COLS * row] = empty;
    }
}

void nk_screen_clear() {
    for (size_t i = 0; i < NUM_ROWS; ++i) {
        nk_screen_clearRow(i);
    }
}

void nk_print_endl() {
    x = 0;

    if(y < NUM_ROWS - 1) {
        y++;
        return;
    }

    for(size_t r = 1; r < NUM_ROWS; r++) {
        for(size_t c = 0; c < NUM_COLS; c++) {
            struct VGA_Char character = buffer[c + NUM_COLS * r];
            buffer[c + NUM_COLS * (r - 1)] = character;
        }
    }
    nk_screen_clearRow(NUM_COLS - 1);
}

void nk_print_char(char character) {
    if(character == '\n') {
        nk_print_endl();
        return;
    }

    if(x > NUM_COLS) nk_print_endl();

    buffer[x + NUM_COLS * y] =  (struct VGA_Char) {
        .character = (uint8_t) character,
        .color = color
    };

    x++;
}

void nk_print_setColor(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}

void nk_print_setBg(uint8_t background) {
    color += (background << 4);
}

void nk_print_setFg(uint8_t foreground) {
    color += foreground;
}
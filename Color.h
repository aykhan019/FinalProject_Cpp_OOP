#pragma once
#include <iostream>
#include <Windows.h>

enum colors {
    BLACK = 0, RED = 4, GREEN = 10, YELLOW = 14, BLUE = 1, PURPLE = 13, CYAN = 3, GREY = 8, WHITE = 15, AQUA = 11
};

void SetColor(int fg, int background = GREY) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, fg | (background << 4));
}
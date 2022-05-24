#pragma once
#include <iostream>
#include <windows.h>

inline void CursorCoordinates(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void HideCursor()
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci;
    ci.dwSize = 25;
    ci.bVisible = false;
    SetConsoleCursorInfo(output, &ci);
}

void ShowCursor()
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci;
    ci.dwSize = 25;
    ci.bVisible = true;
    SetConsoleCursorInfo(output, &ci);
}
#include <iostream>
#include "Color.h"
#include <Windows.h>

void FullScreenMode()
{
    SetColor(GREY, GREY);

    HWND Hwnd = GetForegroundWindow();
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    LONG winstyle = GetWindowLong(Hwnd, GWL_STYLE);
    SetWindowLong(Hwnd, GWL_STYLE, (winstyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(Hwnd, HWND_TOP, 0, 0, x, y, 0);
    HWND console = GetConsoleWindow();
    ShowScrollBar(console, SB_BOTH,false);

}

void Zoom(int fontsize)
{
    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 700;
    fontex.dwFontSize.X = fontsize;
    fontex.dwFontSize.Y = fontsize;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}
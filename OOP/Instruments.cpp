#pragma once
#include "Header.h"



void Cursor(int x, int y)
{

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c{ x, y };
	SetConsoleCursorPosition(hOut, c);

}
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci = CONSOLE_CURSOR_INFO();

void SetColor(int text, int background) {
	SetConsoleTextAttribute(handle, (WORD)((background << 4) | text));
}

void set_cursor_visible(bool visible) {
	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = visible;
	SetConsoleCursorInfo(handle, &cci);
}

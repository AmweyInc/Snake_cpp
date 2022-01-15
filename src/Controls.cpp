#include "Controls.h"

Controls::Controls() {
	x = 0;
	y = 0;
}

void Controls::PrintXY(std::uint16_t x, std::uint16_t y)
{
	COORD position = { Controls::x, Controls::y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, position);
	SetConsoleTitle("Snake");
}

void Controls::CursorVisibles(bool state) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = state;
	SetConsoleCursorInfo(handle, &CursorInfo);
}
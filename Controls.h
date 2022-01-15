#pragma once
#include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

class Controls
{
public:
	Controls();
	~Controls() = default;

	void PrintXY(std::uint16_t x, std::uint16_t y);
	void CursorVisibles(bool state);
private:
	short x;
	short y;
};

#pragma once
#include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "defines.h"


class Field
{
private:
	int x_coord;
	int y_coord;
public:

	char field[y_max][x_max + 1];
	void CreateField(char ch);
	void ShowField();
	void SpawnEgg();

	void SetX(uint16_t x);
	void SetY(uint16_t y);

	int GetX();
	int GetY();
	~Field() = default;
};

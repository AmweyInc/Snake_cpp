#pragma once
#include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "Positiond.h"
#include "eSpin.h"
#include "defines.h"
class Snake
{
public:
	Snake(int length, Spin snakeMouth);
	~Snake() = default;
	void ValuesStart();
	void Motion(char field[y_max][x_max + 1]);
	void AddBody();
	bool IsGameOver();
private:
	int length;
	Positiond SnakePos[500];
	Spin SnakeMouth;
};

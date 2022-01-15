#pragma once
#include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "defines.h"
class Positiond
{
public:
	void SetX(int x);
	void SetY(int y);

	void ValueStart();

	int GetX();
	int GetY();
private:
	int x;
	int y;
};

inline void Positiond::SetX(int x)
{
	this->x = x;
}

inline void Positiond::SetY(int y)
{
	this->y = y;
}

inline void Positiond::ValueStart()
{
	SetX(x_max / 2);
	SetY(y_max / 2);
}

inline int Positiond::GetX()
{
	return x;
}

inline int Positiond::GetY()
{
	return y;
}

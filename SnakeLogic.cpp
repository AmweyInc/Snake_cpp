#include "SnakeLogic.h"
#include "Controls.h"
#include "Positiond.h"
Snake::Snake(int length, Spin snakeMouth)
{
	this->length = length;
}

void Snake::ValuesStart() {
	for (std::size_t i = 0; i < Snake::length; i++)
	{
		SnakePos[i].SetX(0);
		SnakePos[i].SetY(0);
	}

	Snake::length = 1;

	SnakePos->ValueStart();
	Controls ctrl;
	ctrl.PrintXY(SnakePos[0].GetX(), SnakePos[0].GetY());
	putchar(127);
}

void Snake::Motion(char field[y_max][x_max + 1])
{
	if (GetAsyncKeyState('W'))
	{
		SnakeMouth = UP;
	}
	else if (GetAsyncKeyState('S'))
	{
		SnakeMouth = DOWN;
	}
	else if (GetAsyncKeyState('A'))
	{
		SnakeMouth = LEFT;
	}
	else if (GetAsyncKeyState('D'))
	{
		SnakeMouth = RIGHT;
	}

	field[SnakePos[length - 1].GetX()][SnakePos[length - 1].GetY()] = ' ';

	for (std::size_t i = length; i > 0; i--)
	{
		SnakePos[i] = SnakePos[i - 1];
	}

	switch (SnakeMouth)
	{
	case LEFT:
		SnakePos[0].SetX(SnakePos[0].GetX() - 2);
		break;
	case RIGHT:
		SnakePos[0].SetX(SnakePos[0].GetX() + 2);
		break;
	case UP:
		SnakePos[0].SetY(SnakePos[0].GetY() - 1);
		break;
	case DOWN:
		SnakePos[0].SetY(SnakePos[0].GetY() + 1);
		break;
	}

	if (field[SnakePos[0].GetX()][SnakePos[0].GetY()] == '*')
	{
		AddBody();
	}

	field[SnakePos[length - 1].GetX()][SnakePos[length - 1].GetY()] = 'O';

	if (length > 1)
	{
		field[SnakePos[0].GetX()][SnakePos[0].GetY()] = '*';
	}
}

void Snake::AddBody()
{
	SnakePos[length].SetX(SnakePos[length].GetX() - 1);
	SnakePos[length].SetY(SnakePos[length].GetY() - 1);
}

bool Snake::IsGameOver()
{
	bool IsGameOver = FALSE;
	if (SnakePos[0].GetX() <= 0 || SnakePos[0].GetX() >= y_max - 1 ||
		SnakePos[0].GetY() <= 0 || SnakePos[0].GetY() >= x_max - 1)
	{
		IsGameOver = TRUE;
	}

	for (std::size_t i = 2; i < length; i++)
	{
		if (SnakePos[0].GetX() == SnakePos[i].GetX() && SnakePos[0].GetY() == SnakePos[i].GetY())
		{
			IsGameOver = TRUE;
		}
	}
	return IsGameOver;
}


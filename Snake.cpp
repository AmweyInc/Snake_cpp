#include "Header.h"
#include "Controls.h"
#include "Field.h"
#include "SnakeLogic.h"

int main() {
	Controls ctrl;
	Field gameField;
	Snake snake(1, UP);


	srand(time(NULL));

	ctrl.CursorVisibles(false);
	gameField.CreateField(219);
	snake.ValuesStart();

	for (size_t i = 0; i < 20; i++)
	{
		gameField.SpawnEgg();
	}

	while (true)
	{
		if (snake.IsGameOver())
		{
			break;
		}

		snake.Motion(gameField.field);
		gameField.ShowField();

		Sleep(100);
	}

}
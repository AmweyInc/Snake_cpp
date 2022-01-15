# **Snake game C++**
A "**snake**" game developed in **C++** to explore the possibilities of **OOP**.

:white_check_mark: **Game logic**  
:white_check_mark: **Game graphics**  
:white_check_mark: **Game structure**  
:negative_squared_cross_mark: **Universal initialization main function for any G++/GCC/MinGW/MSVC**  
## **Execution:on MinGW**
Create main file in dir with any name,for example `snake.cpp`  
In file `snake.cpp` include all classes from git repository:  
```C++ 
#include "Header.h"
#include "Controls.h"
#include "Field.h"
#include "SnakeLogic.h"
```
After create main function:  
```C++
int main(int argc char** argv){

}
```

Inside the function, initialize the classes for your compiler, the below init works on **MinGW/Cuda C++:** 
```C++
    Controls ctrl;
	Field gameField;
	Snake snake(1, UP);


	srand(time(NULL));

	ctrl.CursorVisibles(false);
	gameField.CreateField(219);
	snake.ValuesStart();
```
Create a food spawn loop for snake:  
```C++
for (size_t i = 0; i < 20; i++)
	{
		gameField.SpawnEgg();
	}
```
Create game loop:  
```C++
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
```
In future will be updated for any compilators.

### Contact with me:
My **e-mail**: <tawergetto2281337@gmail.com> or <amwey1337@vk.com>  
My **discord**: `Amwey#9353`

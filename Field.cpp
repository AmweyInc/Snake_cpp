#include "Field.h"
#include "Controls.h"
#include "defines.h"
void Field::CreateField(char ch)
{
    for (int y = 0; y < y_max; y++)
    {
        for (int x = 0; x < x_max; x++)
        {
            if (y == 0 || y == y_max - 1 ||
                x == 0 || x == x_max - 1)
            {
                field[y][x] = ch;
            }
            else
            {
                field[y][x] = ' ';
            }
        }
        field[y][x_max] = '\0';
    }
}

    void Field::ShowField()
{
    Controls POS;
    POS.PrintXY(0, 0);

    for (int y = 0; y < y_max; y++)
    {
        printf("%s\n", field[y]);
    }
}

void Field::SpawnEgg()
{
    int x = rand() % (x_max - 2) + 1;
    int y = rand() % (y_max - 2) + 1;

    bool isSpawn = false;
    while (true)
    {
        if (x % 2 == 0) isSpawn = true;

        if (field[y][x] == 'O' || field[y][x] == '*') isSpawn = false;

        if (isSpawn) break;

        x = rand() % (x_max - 2) + 1;
    }

    field[y][x] = '*';
}

void Field::SetX(uint16_t x)
{
    this->x_coord = x;
}

void Field::SetY(uint16_t y)
{
    this->y_coord = y;
}

int Field::GetX()
{
    return x_coord;
}

int Field::GetY()
{
    return y_coord;
}

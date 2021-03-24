#include "utils.h"

namespace __utils
{
    void GoToXY(int _x, int _y)
    {
        HANDLE H_CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD dwPosition;

        dwPosition.X = _x;
        dwPosition.Y = _y;

        SetConsoleCursorPosition(H_CONSOLE, dwPosition);
    }

    void Cursor::MoveDown(int _max)
    {
        ptCurrentPosition.y++;
        if (ptCurrentPosition.y > (ptStartPosition.y + _max))
        {
            ptCurrentPosition.y = ptStartPosition.y + _max;
        }
    }

    void Cursor::MoveUp()
    {
        ptCurrentPosition.y--;
        if (ptCurrentPosition.y < ptStartPosition.y)
        {
            ptCurrentPosition.y = ptStartPosition.y;
        }
    }

}
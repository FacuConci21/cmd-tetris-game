#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>

namespace __utils
{

    void GoToXY(int, int);

    struct SPoint
    {
        int x;
        int y;
    };

    class Cursor
    {
        SPoint ptStartPosition;
        SPoint ptCurrentPosition;

    public:
        Cursor(SPoint _ptStart) : ptStartPosition(_ptStart), ptCurrentPosition(_ptStart) {};

        ~Cursor() {};

        inline int GetX_Distance() { return ptCurrentPosition.x - ptStartPosition.x; }
        inline int GetY_Distance() { return ptCurrentPosition.y - ptStartPosition.y; }

        inline void PutCursorInConsole()
        {
            __utils::GoToXY(ptStartPosition.x, ptCurrentPosition.y);
            _putch('>');
        }

        inline void ClearCursorCurrentPosition()
        {
            __utils::GoToXY(ptCurrentPosition.x, ptCurrentPosition.y);
            _putch(' ');
        }

        void MoveDown(int);

        void MoveUp();
    };

}

#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>

#ifndef __UTILS_H
#define __UTILS_H

#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100

#define KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_SPACEBAR 32

namespace __utils
{

    void GoToXY(int, int);

    struct SPoint
    {
        int x;
        int y;
    };

    struct SSize
    {
        const int width;
        const int height;
    };

    template <class Ty>
    struct SArrayPtr
    {
        Ty* data;
        size_t size;
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

#endif
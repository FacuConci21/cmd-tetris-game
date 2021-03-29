#pragma once

#include <iostream>
#include <array>
#include <conio.h>
#include <string>
#include <math.h>
#include <thread>
#include <ctime>

#include "utils.h"
#include "Shape.h"

using namespace std;

#ifndef Game_H
#define Game_H

class Game
{
	static const string hsSymbols;

	static inline void DisplayShape(short* ptrShape, size_t nSqrtSizeShape, int x, int y)
	{
		size_t i = 0, d = 0;// _x = x;
		for (; i < (nSqrtSizeShape*nSqrtSizeShape) ; i += nSqrtSizeShape)
		{
			__utils::GoToXY(x, y + d);
			for (size_t j = 0; j < nSqrtSizeShape ; j++)
			{
				if (ptrShape[i + j] != 0) _putch(hsSymbols[ptrShape[i + j]]);
				else _putch(KEY_SPACEBAR);
			}
			d++; //_x = x;
		}
	}

	static inline void ClearRegion(__utils::SPoint ptTopLeft, __utils::SPoint ptBottomRight)
	{
		
		for (int y = 0; y < (ptBottomRight.y - ptTopLeft.y); y++)
		{
			for (int x = 0; x < (ptBottomRight.x - ptTopLeft.x); x++)
			{
				__utils::GoToXY(ptTopLeft.x + x, ptTopLeft.y + y);
				_putch(' ');
			}
		}
	}

public:

	Game() {};
	~Game() {};

	static int Main();
};


#endif // !Game_H




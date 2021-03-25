#pragma once

#include <iostream>
#include <array>
#include <conio.h>
#include <string>
#include <math.h>
#include <array>

#include "utils.h"
#include "Shape.h"

using namespace std;

#ifndef Game_H
#define Game_H

class Game
{
	static string hsSymbols;

	static inline void DisplayShape(short* ptrShape, size_t szSizeShape, int x, int y)
	{
		size_t i = 0, d = 0 ;
		for (; i < szSizeShape; i += sqrt(szSizeShape))
		{
			__utils::GoToXY(x, y + d);
			for (size_t j = 0; j < sqrt(szSizeShape); j++)
			{
				_putch(hsSymbols[ptrShape[i + j]]);
			}
			d++;
		}
	}

public:

	Game() {};
	~Game() {};

	static int Main();
};


#endif // !Game_H




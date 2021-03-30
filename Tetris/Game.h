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
	static const __utils::SPoint ptStartingMapPosition;
	static const size_t nMapMatrixWidth;
	static const size_t nMapMatrixHeight;

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

	static inline void FillMapMatrix(Shape* cShape, array<array<short, 18>, 20> &nMap, int nCurrentShape, int nSqrtShapeSize)
	{
		int nDifW = (nMapMatrixWidth + ptStartingMapPosition.x) - cShape->X(),
			nDifH = (nMapMatrixHeight + ptStartingMapPosition.y) - cShape->Y(),
			nShapesIndex = 0, nCellValue;

		for (size_t r = 0; r < nSqrtShapeSize; r++)
		{
			for (size_t c = 0; c < nSqrtShapeSize; c++)
			{
				nCellValue = cShape->ptrsMemberShapes[nCurrentShape].data[nShapesIndex];
				if (nCellValue) nMap[(nMapMatrixHeight - nDifH) + r][(nMapMatrixWidth - nDifW) + c] = nCellValue;
				nShapesIndex++;
			}
		}
	}

public:

	Game() {};
	~Game() {};

	static int Main();
};


#endif // !Game_H




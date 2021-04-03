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
	static const size_t nMapMatrixWidth = 16;
	static const size_t nMapMatrixHeight = 18;
	static int nPlayerScore;

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

	static inline void FillMapMatrix(Shape* cShape, array<array<short, nMapMatrixWidth>, nMapMatrixHeight > &nMap,
		int nCurrentShape, int nSqrtShapeSize)
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

	static inline bool ShapesCollison(Shape* cShape, array<array<short, nMapMatrixWidth>, nMapMatrixHeight>& nMap,
		int nCurrentShape, int nSqrtShapeSize)
	{
		int nDifW = (nMapMatrixWidth + ptStartingMapPosition.x) - (cShape->X() + nSqrtShapeSize),
			nDifH = (nMapMatrixHeight + ptStartingMapPosition.y) - (cShape->Y() + nSqrtShapeSize),
			nShapeIndex = (int) cShape->ptrsMemberShapes[nCurrentShape].size - 1,
			nShapeElement, nMapElement, nColumnDecrement;

		for (int r = nSqrtShapeSize - 1; r >= (int)(nSqrtShapeSize / 2); r--)
		{
			nColumnDecrement = 1;

			for (int c = nSqrtShapeSize - 1; c >= 0; c--)
			{
				nShapeElement = cShape->ptrsMemberShapes[nCurrentShape].data[nShapeIndex];
				nMapElement = nMap[(nMapMatrixHeight - 1) - nDifH][nMapMatrixWidth - nDifW - nColumnDecrement];

				if (nShapeElement && nMapElement)
					return true;

				nShapeIndex--; nColumnDecrement++;
			}
		}
		return false;
	}

	static inline bool IsRowFilled(array<array<short, nMapMatrixWidth>, nMapMatrixHeight>& nMap, int r)
	{
		bool bIsFilled = false;

		for (int c = 1; c < nMap[r].size() - 1; c++)
		{
			if (nMap[r][c]) bIsFilled = true;
			else return bIsFilled = false;
		}

		return bIsFilled;
	}

	static inline void ReFillMapMatrix(array<array<short, nMapMatrixWidth>, nMapMatrixHeight >& nMap, int _row)
	{
		for (size_t r = _row; r > 0; r--)
			for (size_t c = 1; c < (nMapMatrixWidth -1); c++)
				nMap[r][c] = nMap[r - 1][c];
	}

public:

	Game() {};
	~Game() {};

	static int Main();
};


#endif // !Game_H




#include "Game.h"

const string Game::hsSymbols = " ABCDE#";
const __utils::SPoint Game::ptStartingMapPosition = { 30, 5 };
const size_t Game::nMapMatrixWidth = 18;
const size_t Game::nMapMatrixHeight = 20;

int Game::Main()
{
	
	array<array<short, nMapMatrixWidth>, nMapMatrixHeight> nMapMatrix;

	Shape cShape({ ptStartingMapPosition.x + 1, ptStartingMapPosition.y },
		{ ptStartingMapPosition.x + (int)(nMapMatrixWidth / 2), ptStartingMapPosition.y },
		{ nMapMatrixWidth - 2, nMapMatrixHeight });

	short nRotationRatio = 0;
	int nCurrentShape = 2;
	bool bPieceFix = false;
	bool bInGame = true; 
	int nSqrtCurrentShapeSize;

	/*		INITIALIZING MAP MATRIX		 */
	for (size_t i = 0; i < nMapMatrixHeight; i++)
	{
		nMapMatrix[i][0] = 6;
		nMapMatrix[i][nMapMatrixWidth-1] = 6;

		for (size_t j = 1; j < (nMapMatrixWidth-1) ; j++) nMapMatrix[i][j] = 0;
	}

	for (size_t j = 1; j < nMapMatrixWidth ; j++) nMapMatrix[nMapMatrixHeight-1][j] = 6;

	/*		STABLISHING THE FIRST SHAPE TO BE DISPLAYED		*/
	srand((int)time(0));

	nCurrentShape = (rand() % 4);
	nSqrtCurrentShapeSize = (int)sqrt(cShape.ptrsMemberShapes[nCurrentShape].size);


	/*		GAME LOOP		*/

	while (bInGame)
	{
		/*			TIMING AND INPUTS		*/
		
		this_thread::sleep_for(100ms); // es el tiempo mas  optimo hasta ahora.

		while (_kbhit())
		{
			switch (_getch())
			{
			case KEY_A:
				cShape.DecrementX();
				break;
			case KEY_D:
				cShape.IncrementX(nSqrtCurrentShapeSize);
				break;
			case KEY_ENTER:
				nRotationRatio++;

				if (nRotationRatio > 3) nRotationRatio = 0;
					
				break;
			case KEY_ESCAPE:
				return 0;
			}
		}

		/*			GAME LOGIC				

		{
			//size_t nShapeSize = cShape.ptrsMemberShapes[nCurrentShape].size;

			int nDifW = (nMapMatrixWidth + ptStartingMapPosition.x) - (cShape.X() + nSqrtCurrentShapeSize),
				nDifH = (nMapMatrixHeight + ptStartingMapPosition.y) - (cShape.Y() + nSqrtCurrentShapeSize),
				nShapeIndex = 0, nShapeElement, nMapElement, nColumnDecrement = 0;

			for (int r = nSqrtCurrentShapeSize -1; r >= (int)(nSqrtCurrentShapeSize / 2); r--)
			{
				for (int c = nSqrtCurrentShapeSize -1; c >= 0; c--)
				{
					nShapeElement = cShape.ptrsMemberShapes[nCurrentShape].data[nShapeIndex];
					nMapElement = nMapMatrix[nMapMatrixHeight - nDifH][nMapMatrixWidth - nDifW - nColumnDecrement];

					if (nShapeElement && nMapElement && !bPieceFix)
					{
						bPieceFix = true;
						break;
					}
					
					nShapeIndex++; nColumnDecrement++;
				}
				nColumnDecrement = 0;
			}
		}*/

		if (bPieceFix)
		{
			FillMapMatrix(&cShape, nMapMatrix, nCurrentShape, nSqrtCurrentShapeSize);

			nCurrentShape = (rand() % 4);
			nSqrtCurrentShapeSize = (int)sqrt(cShape.ptrsMemberShapes[nCurrentShape].size);
			cShape.RestartCurrentPoint();
			bPieceFix = false;
		}

		Shape::Rotate(cShape.ptrsMemberShapes[nCurrentShape].data, cShape.ptrsMemberShapes[nCurrentShape].size, nRotationRatio, nCurrentShape);

		/*			DISPLAY					*/

		// Display map.

		for (size_t i = 0; i < nMapMatrixHeight - 1; i++)
		{
			__utils::GoToXY(ptStartingMapPosition.x, ptStartingMapPosition.y + i);
			for (size_t j = 0; j < nMapMatrixWidth; j++) _putch(hsSymbols[nMapMatrix[i][j]]);
		}

		DisplayShape(cShape.ptrsMemberShapes[nCurrentShape].data, nSqrtCurrentShapeSize, cShape.X(), cShape.Y());

		// Draw floor

		__utils::GoToXY(ptStartingMapPosition.x, ptStartingMapPosition.y + nMapMatrixHeight - 1);
		for (size_t j = 0; j < nMapMatrixWidth; j++) _putch(hsSymbols[nMapMatrix[nMapMatrixHeight - 1][j]]);
			
		// Increment Y coord of Shape class object to define its next position.
		bPieceFix = cShape.IncrementY(nSqrtCurrentShapeSize);
	}

	return 0;
}
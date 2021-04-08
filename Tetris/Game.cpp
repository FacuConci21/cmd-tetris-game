#include "Game.h"

const string Game::hsSymbols = " ABCDE#";
const __utils::SPoint Game::ptStartingMapPosition = { 30, 5 };
int Game::nPlayerScore = 0;
bool Game::bInGame = true;
int Game::nGameExit = 0;
int* Game::ptrCurrentShape = nullptr;
Shape* Game::ptrShape = nullptr;

int Game::Main()
{
	
	array<array<short, nMapMatrixWidth>, nMapMatrixHeight> nMapMatrix;

	Shape cShape({ ptStartingMapPosition.x + 1, ptStartingMapPosition.y },
		{ ptStartingMapPosition.x + (int)(nMapMatrixWidth / 2), ptStartingMapPosition.y },
		{ nMapMatrixWidth - 2, nMapMatrixHeight });

	bool bPieceFix = false;
	bool bIsRowFilled = false;
	short nRotationRatio = 0;
	int nRowFilled = -1;
	int nCurrentShape;
	int nSqrtCurrentShapeSize;

	/*		INITIALIZING POINTERS		*/

	ptrCurrentShape = &nCurrentShape;
	ptrShape = &cShape;

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

	nCurrentShape = (rand() % 5);
	nSqrtCurrentShapeSize = (int)sqrt(cShape.ptrsMemberShapes[nCurrentShape].size);

	/*		GAME LOOP		*/

	while (bInGame)
	{
		/*				TIMING AND INPUTS		*/
		
		this_thread::sleep_for(170ms); // es el tiempo mas  optimo hasta ahora.

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
				PauseMenu();
				break;

			}
		}

		/*				GAME LOGIC				*/

		if (bIsRowFilled)
		{
			ReFillMapMatrix(nMapMatrix, nRowFilled);
			bIsRowFilled = false;
			nRowFilled = -1;
		}

		// comprueba que la figura haya tocado el piso.
		bPieceFix = cShape.IsTouchingFloor(nSqrtCurrentShapeSize);

		// de no tocar el piso comprueba que no toque otra figura en el mapa.
		if (!bPieceFix) bPieceFix = ShapesCollison(&cShape, nMapMatrix, nCurrentShape, nSqrtCurrentShapeSize);
		
		if (bPieceFix)
		{
			int nDifH = (nMapMatrixHeight + ptStartingMapPosition.y) - (cShape.Y() + nSqrtCurrentShapeSize);

			FillMapMatrix(&cShape, nMapMatrix, nCurrentShape, nSqrtCurrentShapeSize);

			if (IsRowFilled(nMapMatrix, ((nMapMatrixHeight - 1) - nDifH)))
			{
				nRowFilled = (nMapMatrixHeight -1) - nDifH;
				nPlayerScore += 10;
			}

			nCurrentShape = (rand() % 4);
			nSqrtCurrentShapeSize = (int)sqrt(cShape.ptrsMemberShapes[nCurrentShape].size);
			cShape.RestartCurrentPoint();
 			nRotationRatio = 0;
			bPieceFix = false;
		}

		for (size_t c = 1; c < (nMapMatrixWidth - 1); c++)
		{
			if (nMapMatrix[1][c]) {
				bInGame = false;
				nGameExit = 0;
			}
		}

		Shape::Rotate(cShape.ptrsMemberShapes[nCurrentShape].data, cShape.ptrsMemberShapes[nCurrentShape].size, nRotationRatio, nCurrentShape);

		/*				DISPLAY					*/

		// Display Score

		__utils::GoToXY(ptStartingMapPosition.x + 2, 3);
		cout << "= SCORE : " << nPlayerScore << " =";

		// Display map.

		for (size_t i = 0; i < (nMapMatrixHeight - 1); i++)
		{
			__utils::GoToXY(ptStartingMapPosition.x, ptStartingMapPosition.y + i);
			if (i == nRowFilled)
			{
				_putch(hsSymbols[nMapMatrix[i][0]]);
				for (size_t j = 1; j < nMapMatrixWidth-1; j++) { _putch('='); }
				_putch(hsSymbols[nMapMatrix[i][nMapMatrixWidth-1]]);
				bIsRowFilled = true;
			}
			else
			{
				for (size_t j = 0; j < nMapMatrixWidth; j++) { _putch(hsSymbols[nMapMatrix[i][j]]); }
			}
		}

		DisplayShape(cShape.ptrsMemberShapes[nCurrentShape].data, nSqrtCurrentShapeSize, cShape.X(), cShape.Y());

		// Draw floor

		__utils::GoToXY(ptStartingMapPosition.x, ptStartingMapPosition.y + nMapMatrixHeight - 1);
		for (size_t j = 0; j < nMapMatrixWidth; j++) _putch(hsSymbols[nMapMatrix[nMapMatrixHeight - 1][j]]);
			
		// Increment Y coord of Shape class object to define its next position.
		cShape.IncrementY();
	}

	bInGame = true;

	return nGameExit;
}
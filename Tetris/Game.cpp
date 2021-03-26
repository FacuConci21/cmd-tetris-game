#include "Game.h"

string Game::hsSymbols = " #ABCDEF";

int Game::Main()
{
	bool bInGame = true;
	__utils::SPoint ptStartingMapPosition = { 30, 5 };
	const size_t nMapMatrixWidth = 18;
	const size_t nMapMatrixHeight = 20;
	array<array<short, nMapMatrixWidth>, nMapMatrixHeight> nMapMatrix;
	Shape cShape({ ptStartingMapPosition.x + (int)(nMapMatrixWidth / 2), ptStartingMapPosition.y - 1 },
		{ nMapMatrixWidth - 2, nMapMatrixHeight - 1 });
	short nRotationRatio = 0;

	/*		INITIALIZING MAP MATRIX		 */
	for (size_t i = 0; i < nMapMatrixHeight; i++)
	{
		nMapMatrix[i][0] = 1;
		nMapMatrix[i][nMapMatrixWidth-1] = 1;

		for (size_t j = 1; j < (nMapMatrixWidth-1) ; j++)
		{
			nMapMatrix[i][j] = 0;
		}
	}
	for (size_t j = 1; j < nMapMatrixWidth ; j++)
	{
		nMapMatrix[nMapMatrixHeight-1][j] = 1;
	}

	/*		DISPLAY	MAP		*/

	for (size_t i = 0; i < nMapMatrixHeight; i++)
	{
		__utils::GoToXY(ptStartingMapPosition.x, ptStartingMapPosition.y + i);

		for (size_t j = 0; j < nMapMatrixWidth; j++)
		{
			_putch( hsSymbols[nMapMatrix[i][j]]);
		}
	}

	/*		GAME LOOP		*/

	while (bInGame)
	{
		/*		TIMING AND INPUTS		*/
		
		this_thread::sleep_for(1000ms);

		while (_kbhit())
				{
					switch (_getch())
					{
					case KEY_A:
						cShape.DecrementX();
						break;
					case KEY_D:
						cShape.IncrementX();
						break;
					case KEY_ENTER:
						nRotationRatio++;
						if (nRotationRatio > 3)
							nRotationRatio = 0;
						break;
					case KEY_ESCAPE:
						return 0;
					}
			}

		/*		GAME LOGIC				*/

		Shape::Rotate(cShape.ns_shape6.data(), cShape.ns_shape6.size(), nRotationRatio);

		cShape.IncrementY();

		/*		DISPLAY					*/

		ClearRegion({ ptStartingMapPosition.x + 1, ptStartingMapPosition.y },
			{ cShape.X() + (int)sqrt(Shape::nszShape6.size()), cShape.Y() + (int)sqrt(Shape::nszShape6.size()) });

		DisplayShape(cShape.ns_shape6.data(), cShape.ns_shape6.size(), cShape.X(), cShape.Y());

		// draw floor

		for (size_t j = 1; j < nMapMatrixWidth; j++)
		{
			__utils::GoToXY(ptStartingMapPosition.x + j, ptStartingMapPosition.y + nMapMatrixHeight - 1);
			_putch(hsSymbols[nMapMatrix[nMapMatrixHeight - 1][j]]);
		}
			
	}

	return 0;
}
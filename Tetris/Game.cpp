#include "Game.h"

string Game::hsSymbols = " #ABCDEF";

int Game::Main()
{
	__utils::SPoint ptStartingMapPosition = { 30, 5 };
	const size_t nMapMatrixWidth = 18;
	const size_t nMapMatrixHeight = 20;
	array<array<short, nMapMatrixWidth>, nMapMatrixHeight> nMapMatrix;
	Shape cShape({ ptStartingMapPosition.x + 1, ptStartingMapPosition.y }, { nMapMatrixWidth - 2, nMapMatrixHeight - 1 });

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
		nMapMatrix[(20)-1][j] = 1;
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

	DisplayShape(Shape::nszShape2.data(), Shape::nszShape2.size(), cShape.X(), cShape.Y());
	DisplayShape(Shape::nszShape3.data(), Shape::nszShape3.size(), cShape.X()+3, cShape.Y());
	DisplayShape(Shape::nszShape4.data(), Shape::nszShape4.size(), cShape.X()+5, cShape.Y());



	return 0;
}
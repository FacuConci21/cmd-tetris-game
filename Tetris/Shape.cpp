#include "Shape.h"

Shape::Shape(__utils::SPoint _ptShapesStartingPoint, __utils::SSize _sShapesLimits) :
	ptShapesStartingPoint(_ptShapesStartingPoint),
	ptShapesCurrentPoint(_ptShapesStartingPoint),
	sShapesLimits(_sShapesLimits),
	nsShape2(nszShape2)
	{};

int Shape::X()
{
	return ptShapesCurrentPoint.x;
}

int Shape::Y()
{
	return ptShapesCurrentPoint.y;
}

inline int Shape::Width()
{
	return sShapesLimits.width;
}

inline int Shape::Height()
{
	return sShapesLimits.height;
}

std::array<short, 4 * 4> Shape::nszShape4 = { 0,0,4,0, 0,0,4,0, 0,0,4,0, 0,0,4,0 };

std::array<short, 3 * 3> Shape::nszShape2 = { 0,2,0,2,2,0,2,0,0 };

std::array<short, 3 * 3> Shape::nszShape5 = { 0,0,0,0,5,0,5,5,5 };

std::array<short, 3 * 3> Shape::nszShape6 = { 0,0,0,6,0,0,6,6,6 };

std::array<short, 2 * 2> Shape::nszShape3 = { 3,3,3,3 };

short* Shape::rotate(short * ptrShape, size_t nShapeSize)
{
	const size_t nAuxArraySize = nShapeSize;
	const size_t nSquareRoot = (size_t)sqrt(nShapeSize);

	for (size_t c = 0; c < nSquareRoot ; c++)
	{
		for (size_t f = 0; f < nSquareRoot; f ++ )
		{

		}
	}
	 
	return ptrShape;
}
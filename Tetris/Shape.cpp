#include "Shape.h"

Shape::Shape(__utils::SPoint _ptShapesStartingPoint, __utils::SSize _sShapesLimits) :
	ptShapesStartingPoint(_ptShapesStartingPoint),
	ptShapesCurrentPoint(_ptShapesStartingPoint),
	sShapesLimits(_sShapesLimits),
	ns_shape2(nszShape2),
	ns_shape4(nszShape4),
	ns_shape5(nszShape5),
	ns_shape6(nszShape6)
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

short* Shape::Rotate(short * ptrShape, size_t nShapeSize, short nRotationRatio)
{
	const size_t nSquareRoot = (size_t)sqrt(nShapeSize);
	size_t nShapeIndex = 0, nCpyIndex;

	for (size_t r = 0; r < nSquareRoot; r++)
	{
		for (size_t c = 0; c < nSquareRoot; c++)
		{
			nCpyIndex = RotationFormula(r, c, nSquareRoot, nRotationRatio);
			ptrShape[nShapeIndex] = Shape::nszShape6[nCpyIndex];
			nShapeIndex++;
		}
	}
	 
	return ptrShape;
}
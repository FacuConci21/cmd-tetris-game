#include "Shape.h"

Shape::Shape(__utils::SPoint _ptShapesStartingPoint, __utils::SSize _sShapesLimits) :
	ptShapesStartingPoint(_ptShapesStartingPoint),
	ptShapesCurrentPoint(_ptShapesStartingPoint),
	sShapesLimits(_sShapesLimits)
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


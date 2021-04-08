#include "Shape.h"

Shape::Shape(__utils::SPoint _ptTopLeft, __utils::SPoint _ptShapesStartingPoint, __utils::SSize _sShapesLimits) :
	ptTopLeft(_ptTopLeft),
	ptShapesStartingPoint(_ptShapesStartingPoint),
	ptShapesCurrentPoint(_ptShapesStartingPoint),
	sShapesLimits(_sShapesLimits),
	ns_shape1(nszShape1),
	ns_shape2(nszShape2),
	ns_shape3(nszShape3),
	ns_shape4(nszShape4),
	ns_shape5(nszShape5)
{
	ptrsMemberShapes[0] = { ns_shape1.data(), ns_shape1.size() };
	ptrsMemberShapes[1] = { ns_shape2.data(), ns_shape2.size() };
	ptrsMemberShapes[2] = { ns_shape3.data(), ns_shape3.size() };
	ptrsMemberShapes[3] = { ns_shape4.data(), ns_shape4.size() };
	ptrsMemberShapes[4] = { ns_shape5.data(), ns_shape5.size() };
};

int Shape::X()
{
	return ptShapesCurrentPoint.x;
}

int Shape::Y()
{
	return ptShapesCurrentPoint.y;
}

__utils::SPoint& Shape::PtTopLeft()
{
	return ptTopLeft;
}

__utils::SPoint& Shape::PtStartingPoint()
{
	return ptShapesStartingPoint;
}

__utils::SPoint& Shape::PtCurrentPoint()
{
	return ptShapesCurrentPoint;
}

__utils::SSize& Shape::SShapeLimits()
{
	return sShapesLimits;
}

bool Shape::IsTouchingFloor(int nSqrtCurrentShapeSize)
{
	if ((ptTopLeft.y + sShapesLimits.height) == (ptShapesCurrentPoint.y + nSqrtCurrentShapeSize))
	{
		ptShapesCurrentPoint.y--;
		return true;
	}
	return false;
}

void Shape::RestartCurrentPoint()
{
	ptShapesCurrentPoint.x = ptShapesStartingPoint.x;
	ptShapesCurrentPoint.y = ptShapesStartingPoint.y;
}

std::array<short, 4 * 4> Shape::nszShape3 = { 0,0,0,3, 0,0,0,3, 0,0,0,3, 0,0,0,3 };

std::array<short, 3 * 3> Shape::nszShape1 = { 0,1,0,1,1,0,1,0,0 };

std::array<short, 3 * 3> Shape::nszShape4 = { 0,0,0,0,5,0,5,5,5 };

std::array<short, 3 * 3> Shape::nszShape5 = { 0,0,0,5,0,0,5,5,5 };

std::array<short, 2 * 2> Shape::nszShape2 = { 2,2,2,2 };

std::array<short*, 5> Shape::ptrsStaticShapes = { Shape::nszShape1.data(), Shape::nszShape2.data(), Shape::nszShape3.data(),
	Shape::nszShape4.data(), Shape::nszShape5.data() };

short* Shape::Rotate(short * ptrShape, size_t nShapeSize, short nRotationRatio, int nCurrentShape)
{
	const size_t nSquareRoot = (size_t)sqrt(nShapeSize);
	size_t nShapeIndex = 0, nCpyIndex;

	for (size_t r = 0; r < nSquareRoot; r++)
	{
		for (size_t c = 0; c < nSquareRoot; c++)
		{
			nCpyIndex = RotationFormula(r, c, nSquareRoot, nRotationRatio);
			ptrShape[nShapeIndex] = Shape::ptrsStaticShapes[nCurrentShape][nCpyIndex];
			nShapeIndex++;
		} 
	}
	 
	return ptrShape;
}
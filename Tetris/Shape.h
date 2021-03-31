#pragma once

#include <iostream>
#include <array>

#include "utils.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	__utils::SPoint ptTopLeft;
	__utils::SPoint ptShapesStartingPoint;
	__utils::SPoint ptShapesCurrentPoint;
	__utils::SSize sShapesLimits;

	static inline size_t RotationFormula(size_t r, size_t c, int w, int ratio)
	{
		switch (ratio)
		{
		case 0: return (r * w) + c;
		case 1: return (w * (w - 1)) + r - (c * w);
		case 2: return ((w * w) - 1) - (w * r) - c;
		case 3: return (w - 1) - r + (c * w);
		}
	}

public:

	Shape(__utils::SPoint, __utils::SPoint, __utils::SSize);
	~Shape() {};

	std::array<__utils::SArrayPtr<short> , 5> ptrsMemberShapes;

	std::array<short, 3 * 3> ns_shape1;
	std::array<short, 2 * 2> ns_shape2;
	std::array<short, 4 * 4> ns_shape3;
	std::array<short, 3 * 3> ns_shape4;
	std::array<short, 3 * 3> ns_shape5;

	int X();
	int Y();
	int Width();
	int Height();

	inline void IncrementX(int nSqrtCurrentShapeSize)
	{
		ptShapesCurrentPoint.x++;
		if ((ptTopLeft.x + sShapesLimits.width) <= (ptShapesCurrentPoint.x + nSqrtCurrentShapeSize))
			ptShapesCurrentPoint.x = ptTopLeft.x + sShapesLimits.width - nSqrtCurrentShapeSize;
	}
	inline void IncrementY()
	{
		ptShapesCurrentPoint.y++;
		
	}
	inline void DecrementX()
	{
		ptShapesCurrentPoint.x--;
		if (ptTopLeft.x >= ptShapesCurrentPoint.x) ptShapesCurrentPoint.x = ptTopLeft.x;
			
	}

	bool IsTouchingFloor(int);

	void RestartCurrentPoint();

	// 4x4 shapes.
	static std::array<short, 4 * 4> nszShape3;

	// 3x3 shapes.
	static std::array<short, 3 * 3> nszShape1;
	static std::array<short, 3 * 3> nszShape4;
	static std::array<short, 3 * 3> nszShape5;

	// 2x2 shapes.
	static std::array<short, 2 * 2> nszShape2;

	static std::array<short*, 5> ptrsStaticShapes;

	static short* Rotate(short *, size_t, short, int);
};

#endif // !SHAPE_H




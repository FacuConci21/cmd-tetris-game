#pragma once

#include <iostream>
#include <array>

#include "utils.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
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

	Shape(__utils::SPoint, __utils::SSize);
	~Shape() {};

	std::array<short, 3 * 3> ns_shape2;
	std::array<short, 4 * 4> ns_shape4;
	std::array<short, 3 * 3> ns_shape5;
	std::array<short, 3 * 3> ns_shape6;

	int X();
	int Y();
	int Width();
	int Height();

	inline void IncrementX()
	{
		ptShapesCurrentPoint.x++;
	}
	inline void IncrementY()
	{
		ptShapesCurrentPoint.y++;
	}
	inline void DecrementX()
	{
		ptShapesCurrentPoint.x--;
	}
	inline void DecrementY()
	{
		ptShapesCurrentPoint.y--;
	}

	// 4x4 shapes.
	static std::array<short, 4 * 4> nszShape4;

	// 3x3 shapes.
	static std::array<short, 3 * 3> nszShape2;
	static std::array<short, 3 * 3> nszShape5;
	static std::array<short, 3 * 3> nszShape6;

	// 2x2 shapes.
	static std::array<short, 2 * 2> nszShape3;

	static short* Rotate(short *, size_t, short);
};

#endif // !SHAPE_H




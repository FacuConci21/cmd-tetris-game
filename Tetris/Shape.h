#pragma once

#include <iostream>
#include <array>

#include "utils.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	__utils::SPoint ptShapesStartingPoint;
	__utils::SSize sShapesLimits;

public:

	Shape(__utils::SPoint, __utils::SSize);
	~Shape() {};

	int X();
	int Y();
	inline int Width();
	inline int Height();

	// 4x4 shapes.
	static std::array<short, 4 * 4> nszShape4;

	// 3x3 shapes.
	static std::array<short, 3 * 3> nszShape2;
	static std::array<short, 3 * 3> nszShape5;
	static std::array<short, 3 * 3> nszShape6;

	// 2x2 shapes.
	static std::array<short, 2 * 2> nszShape3;


};

#endif // !SHAPE_H




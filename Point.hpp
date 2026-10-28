#pragma once

#include "Direction.hpp"

struct Point
{
	int x{};
	int y{};

	Point getAdjacentPoint(const Direction& d) const;
	friend bool operator==(const Point& p1, const Point& p2);
	friend bool operator!=(const Point& p1, const Point& p2);
};
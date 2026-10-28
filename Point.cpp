#include "Direction.hpp"
#include "Point.hpp"
#include <cassert>
#include <tuple>
#include <utility>

Point Point::getAdjacentPoint(const Direction& d) const
{
	using enum Direction::Types;

	switch (d.getType())
	{
	case up:
		return Point{ x, y - 1 };
	case left:
		return Point{ x - 1, y };
	case down:
		return Point{ x, y + 1 };
	case right:
		return Point{ x + 1, y };
	default:
		assert(!"Missing cases for enumerators.");
		std::unreachable();
	}
}

bool operator==(const Point& p1, const Point& p2)
{
	return std::tie(p1.x, p1.y) == std::tie(p2.x, p2.y);
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}
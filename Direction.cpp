#include "Direction.hpp"
#include "Random.h"
#include <cassert>
#include <string_view>
#include <utility>

namespace
{
	constexpr std::string_view toString(Direction::Types dt)
	{
		using enum Direction::Types;

		switch (dt)
		{
		case up:
			return "up";
		case left:
			return "left";
		case down:
			return "down";
		case right:
			return "right";
		default:
			assert(!"Missing cases for enumerators.");
			std::unreachable();
		}
	}

	std::ostream& operator<<(std::ostream& out, Direction::Types dt)
	{
		return out << toString(dt);
	}
}

Direction::Direction(Types t)
	: m_direction{ t }
{
}

Direction::Types Direction::getType() const
{
	return m_direction;
}

std::ostream& operator<<(std::ostream& out, const Direction& d)
{
	return out << d.getType();
}

Direction Direction::operator-() const
{
	switch (m_direction)
	{
	case up:
		return down;
	case left:
		return right;
	case down:
		return up;
	case right:
		return left;
	default:
		assert(!"Missing cases for enumerators.");
		std::unreachable();
	}
}

Direction Direction::getRandomDirection()
{
	return Direction::Types{ Random::get(Direction::Types{}, maxTypes - 1) };
}
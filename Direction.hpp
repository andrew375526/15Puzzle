#pragma once

#include <iostream>

class Direction
{
public:
	enum Types : int
	{
		up,
		left,
		down,
		right,
		maxTypes
	};

	Direction(Types t);
	Types getType() const;
	Direction operator-() const;
	static Direction getRandomDirection();

private:
	Types m_direction{};
};

std::ostream& operator<<(std::ostream& out, const Direction& d);
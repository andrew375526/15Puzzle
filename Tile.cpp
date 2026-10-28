#include "Tile.hpp"
#include <iostream>

Tile::Tile(int num)
	: m_num{ num }
{
}

int Tile::getNum() const
{
	return m_num;
}

bool isEmpty(const Tile& t)
{
	return t.getNum() == 0;
}

std::ostream& operator<<(std::ostream& out, const Tile& t)
{
	if (t.getNum() < 10) out << "  ";
	else out << " ";
	if (isEmpty(t)) return out << "   ";
	return out << t.getNum() << " ";
}

bool operator==(const Tile& t1, const Tile& t2)
{
	return t1.getNum() == t2.getNum();
}

bool operator!=(const Tile& t1, const Tile& t2)
{
	return !(t1 == t2);
}
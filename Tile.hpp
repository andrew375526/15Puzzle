#pragma once

#include <iostream>

class Tile
{
public:
	Tile() = default;
	explicit Tile(int num);
	int getNum() const;

private:
	int m_num{ 0 };
};

bool isEmpty(const Tile& t);
std::ostream& operator<<(std::ostream& out, const Tile& tile);
bool operator==(const Tile& t1, const Tile& t2);
bool operator!=(const Tile& t1, const Tile& t2);
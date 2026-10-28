#pragma once

#include "Direction.hpp"
#include "Point.hpp"
#include "Tile.hpp"
#include <iostream>

class Board
{
public:
	Board() = default;
	void shuffle(int count);
	bool moveTile(Direction d);
	bool isSolved() const;
	friend std::ostream& operator<<(std::ostream& out, const Board& board);
	friend bool operator==(const Board& b1, const Board& b2);

private:
	static constexpr auto s_rowLength{ 4 };
	static constexpr auto s_colLength{ 4 };

	Tile m_board[s_rowLength][s_colLength]{
		{Tile{1},  Tile{2},  Tile{3},  Tile{4}},
		{Tile{5},  Tile{6},  Tile{7},  Tile{8}},
		{Tile{9},  Tile{10}, Tile{11}, Tile{12}},
		{Tile{13}, Tile{14}, Tile{15}, Tile{}}
	};

	Point findEmptyTile() const;
	static bool isOnBoard(const Point& p);
};
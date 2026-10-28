#include "Board.hpp"
#include "Direction.hpp"
#include "Point.hpp"
#include "Tile.hpp"
#include <cassert>
#include <iostream>
#include <utility>

#define PASS

namespace
{
	constexpr auto g_consoleLines{ 25 };

	void printEmptyLines(int count)
	{
		for (auto i{ 0 }; i < count; ++i) std::cout << "\n";
	}
}

void Board::shuffle(int count)
{
	for (auto i{ 0 }; i < count; ++i)
		while (!moveTile(Direction::getRandomDirection())) PASS;
}

Point Board::findEmptyTile() const
{
	for (auto row{ 0 }; row < s_rowLength; ++row)
		for (auto col{ 0 }; col < s_colLength; ++col)
			if (isEmpty(m_board[row][col])) return { col, row };

	assert(!"Board does not contain an empty tile.");
	std::unreachable();
}

bool Board::isOnBoard(const Point& p)
{
	return (p.x >= 0) && (p.y >= 0) && (p.x < s_rowLength)
		&& (p.y < s_colLength);
}

bool Board::moveTile(Direction d)
{
	const auto emptyTilePoint{ findEmptyTile() };
	const auto adjacentTilePoint{ emptyTilePoint.getAdjacentPoint(-d) };
	if (!isOnBoard(adjacentTilePoint)) return false;

	std::swap(
		m_board[emptyTilePoint.y][emptyTilePoint.x],
		m_board[adjacentTilePoint.y][adjacentTilePoint.x]
	);

	return true;
}

bool Board::isSolved() const
{
	Board board{};
	return board == *this;
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
	printEmptyLines(g_consoleLines);

	for (const auto& row : b.m_board)
	{
		for (const auto& tile : row) out << tile;
		out << "\n";
	}

	return out;
}

bool operator==(const Board& b1, const Board& b2)
{
	for (auto row{ 0 }; row < Board::s_rowLength; ++row)
	{
		for (auto col{ 0 }; col < Board::s_colLength; ++col)
			if (b1.m_board[row][col] != b2.m_board[row][col]) return false;
	}

	return true;
}
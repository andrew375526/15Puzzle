#include "Board.hpp"
#include "Direction.hpp"
#include "Point.hpp"
#include "UserInput.hpp"
#include <iostream>

int main()
{
	Board board{};
	board.shuffle(1000);
	std::cout << board;

	while (!board.isSolved())
	{
		auto command{ UserInput::getCommand("Enter a command: ") };

		if (command == 'q')
		{
			std::cout << "\n\nBye!\n\n";
			return 0;
		}

		auto direction{ UserInput::toDirection(command) };
		std::cout << "You entered direction: " << direction << "\n";
		if (board.moveTile(direction)) std::cout << board;
	}

	std::cout << "\n\nYou won!\n\n";
	return 0;
}
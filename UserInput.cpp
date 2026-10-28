#include "Direction.hpp"
#include "Input.h"
#include "UserInput.hpp"
#include <cassert>
#include <iostream>

namespace
{
	constexpr bool isValidCommand(char command)
	{
		switch (command)
		{
		case 'w':
		case 'a':
		case 's':
		case 'd':
		case 'q':
			return true;
		default:
			return false;
		}
	}

	constexpr Direction::Types toDirectionType(char command)
	{
		using enum Direction::Types;

		switch (command)
		{
		case 'w':
			return up;
		case 'a':
			return left;
		case 's':
			return down;
		case 'd':
			return right;
		default:
			assert(!"Missing cases for valid commands.");
			std::unreachable();
		}
	}
}

namespace UserInput
{
	char getChar(std::string_view prompt)
	{
		std::cout << prompt;
		char ch{};
		std::cin >> ch;
		Input::clearFailedExtraction();
		return ch;
	}

	char getCommand(std::string_view prompt)
	{
		while (true)
		{
			auto ch{ getChar(prompt) };
			if (isValidCommand(ch)) return ch;
		}
	}

	Direction toDirection(char command)
	{
		return Direction{ toDirectionType(command) };
	}
}
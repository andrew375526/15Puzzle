#pragma once

#include "Direction.hpp"
#include <string_view>

namespace UserInput
{
	char getChar(std::string_view prompt = "");
	char getCommand(std::string_view prompt = "");
	Direction toDirection(char command);
}
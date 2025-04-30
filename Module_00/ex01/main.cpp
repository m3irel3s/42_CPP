#include <iostream>

#include "PhoneBook.hpp"

int main(void)
{
	std::string cmd;

	while (!std::cin.eof())
	{
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			std::cout << "Hello" << std::endl;
	}
}
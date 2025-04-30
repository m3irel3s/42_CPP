#include <iostream>

#include "PhoneBook.hpp"

int main(void)
{
	std::string cmd;

	while (!std::cin.eof())
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			std::cout << "Hello from add" << std::endl;
		else if (cmd == "SEARCH")
			std::cout << "Hello from search" << std::endl;
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "\nInvalid command\n" << std::endl;
	}
}
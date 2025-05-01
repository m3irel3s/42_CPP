#include <iostream>
#include <string.h>

#include "PhoneBook.hpp"

static void	PrintMenu(void);

int main(void)
{
	std::string cmd;
	PhoneBook phoneBook;

	// phoneBook.FillContacts();
	while (!std::cin.eof())
	{
		PrintMenu();
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phoneBook.AddContact();
		else if (cmd == "SEARCH")
			phoneBook.SearchContact();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "\n\tInvalid command!" << std::endl;
	}
}

static void	PrintMenu(void)
{
	std::cout << "\n\t      MENU\n" << std::endl;
	std::cout << " --------------------------------" << std::endl;
	std::cout << "| ADD\t\tadds new contact |" << std::endl;
	std::cout << "| SEARCH\tsearchs contact  |" << std::endl;
	std::cout << "| EXIT\t\tcloses program   |" << std::endl;
	std::cout << " --------------------------------\n" << std::endl;
	std::cout << "Enter command: ";
}

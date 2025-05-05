#include <iostream>
#include <string.h>

#include "PhoneBook.hpp"

static void	printMenu(void);

int main(void)
{
	std::string cmd;
	PhoneBook phoneBook;

	// phoneBook.fillContacts();
	while (!std::cin.eof())
	{
		printMenu();
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
			phoneBook.searchContact();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "\n\tInvalid command!" << std::endl;
	}
}

static void	printMenu(void)
{
	std::cout << "\n\t      MENU\n" << std::endl;
	std::cout << " --------------------------------" << std::endl;
	std::cout << "| ADD\t\tadds new contact |" << std::endl;
	std::cout << "| SEARCH\tsearchs contact  |" << std::endl;
	std::cout << "| EXIT\t\tcloses program   |" << std::endl;
	std::cout << " --------------------------------\n" << std::endl;
	std::cout << "Enter command: ";
}

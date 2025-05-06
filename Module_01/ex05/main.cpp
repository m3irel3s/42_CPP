#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::string level;
	while(!std::cin.eof())
	{
		std::cout << "\nEnter complain: ";
		std::getline(std::cin, level);
		if (level != "DEBUG" && level != "INFO" && level != "WARNING" 
		&& level != "ERROR")
			std::cout << "invalid command" << std::endl;
		else
			harl.complain(level);
	}
}
#include "ClapTrap.hpp"

static void printSep(void);

int main()
{
	ClapTrap miguel("Miguel");
	printSep();
	std::cout << miguel.getName() << " hit points: " << miguel.getHitPoints() << std::endl;
	std::cout << miguel.getName() << " energy points: " << miguel.getEnergyPoints() << std::endl;
	printSep();
	for (int i = 0; i < 4; i++)
		miguel.attack("John");
	std::cout << miguel.getName() << " hit points: " << miguel.getHitPoints() << std::endl;
	std::cout << miguel.getName() << " energy points: " << miguel.getEnergyPoints() << std::endl;
	printSep();
	for (int i = 0; i < 4; i++)
		miguel.takeDamage(2);
	std::cout << miguel.getName() << " hit points: " << miguel.getHitPoints() << std::endl;
	std::cout << miguel.getName() << " energy points: " << miguel.getEnergyPoints() << std::endl;
	printSep();
	for (int i = 0; i < 7; i++)
		miguel.beRepaired(5);
	std::cout << miguel.getName() << " hit points: " << miguel.getHitPoints() << std::endl;
	std::cout << miguel.getName() << " energy points: " << miguel.getEnergyPoints() << std::endl;
	printSep();
}

static void printSep(void)
{
	std::cout << "----------------------------------" << std::endl;
}

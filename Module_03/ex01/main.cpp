#include "ScavTrap.hpp"

static void printSep(void);

int main(void)
{
	ScavTrap miguel("Miguel");
	printSep();
	std::cout << miguel.getName() << " hit points: " << miguel.getHitPoints() << std::endl;
	std::cout << miguel.getName() << " energy points: " << miguel.getEnergyPoints() << std::endl;
	std::cout << miguel.getName() << " attack damage: " << miguel.getAttackDamage() << std::endl;
	printSep();
	miguel.guardGate();
	miguel.attack("John");
	printSep();
	std::cout << miguel.getName() << " hit points: " << miguel.getHitPoints() << std::endl;
	std::cout << miguel.getName() << " energy points: " << miguel.getEnergyPoints() << std::endl;
	std::cout << miguel.getName() << " attack damage: " << miguel.getAttackDamage() << std::endl;
	printSep();
}


static void printSep(void)
{
	std::cout << "----------------------------------" << std::endl;
}


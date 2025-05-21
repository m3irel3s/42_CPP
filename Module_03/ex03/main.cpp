#include "DiamondTrap.hpp"

static void printSep(void);

int main(void)
{
	DiamondTrap miguel("Miguel");
	printSep();
	std::cout << miguel.getName() << " hit points: " << miguel.getHitPoints() << std::endl;
	std::cout << miguel.getName() << " energy points: " << miguel.getEnergyPoints() << std::endl;
	std::cout << miguel.getName() << " attack damage: " << miguel.getAttackDamage() << std::endl;
	printSep();
	miguel.whoAmI();
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
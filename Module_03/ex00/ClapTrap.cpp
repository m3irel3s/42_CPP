#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(){};

ClapTrap::ClapTrap()
{
	_name = "Clap(Unknown)";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
} 

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return *this;
}









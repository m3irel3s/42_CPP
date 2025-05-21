#include "DiamondTrap.hpp"

// =====================
// Constructor & Desctructor
// =====================

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	FragTrap f;
	_name = "Diamond(Default)";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = f.getHitPoints();
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = f.getAttackDamage();
	std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	FragTrap f;
	_name = name;
	_hitPoints = f.getHitPoints();
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = f.getAttackDamage();
	std::cout << "DiamondTrap name constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

// =====================
// Operator Overload
// =====================

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
		ClapTrap::_name = copy.ClapTrap::_name;
	}
	return *this;
}

// =====================
// Public member functions
// =====================

void DiamondTrap::whoAmI()
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

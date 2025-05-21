#include "ScavTrap.hpp"

// =====================
// Constructor & Destructor
// =====================

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "Scav(Default)";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

// =====================
// Operator overload
// =====================

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
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

// =====================
// Public member functions
// =====================

void ScavTrap::attack(const std::string &target)
{
	if (!hasPoints())
		return ;

	_energyPoints--;
	std::cout << "ScavTrap " << _name
				<< " attacks " << target <<
				", causing " << _attackDamage
				<< " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}

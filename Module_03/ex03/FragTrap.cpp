#include "FragTrap.hpp"

// =====================
// Constructor & Destructor
// =====================

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	_name = "Frag(Default)";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap name constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

// =====================
// Operator overload
// =====================

FragTrap &FragTrap::operator=(const FragTrap &copy)
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
// Public Member Functions
// =====================

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap high five guys!" << std::endl;
}

#include "ClapTrap.hpp"

// =====================
// Constructor & Destructor
// =====================

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap()
{
	_name = "Clap(Default)";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap default constructor called for " << _name << std::endl;
} 

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap name constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

// =====================
// Operator Overload
// =====================

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called for " << _name << std::endl;
	return *this;
}

// =====================
// Public Member Functions
// =====================

void ClapTrap::attack(const std::string &target)
{
	if (!hasPoints())
		return ;

	_energyPoints--;
	std::cout << "ClapTrap " << _name
				<< " attacks " << target <<
				", causing " << _attackDamage
				<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name
				<< " takes " << amount
				<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hasPoints())
		return;
	
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
				<< " regains " << amount 
				<< " hit points" << std::endl;
}

// =====================
// Getters
// =====================

int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }
std::string ClapTrap::getName() const { return _name; }

// =====================
// Setters
// =====================

void ClapTrap::setHitPoints(int hitPoints) { _hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(int energyPoints) { _energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(int attackDamage) { _attackDamage = attackDamage; }

// =====================
// Utils
// =====================

bool ClapTrap::hasPoints() const
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
		return false;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
		return false;
	}
	return true;
}

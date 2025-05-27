#include "Character.hpp"

// =========
// Constructor & destructor
// =========

Character::~Character()
{
	for (int i = 0; i < MAX_SLOTS; i++)
		delete _inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character::Character() : _name("Default")
{
	for (int i = 0; i < MAX_SLOTS; i++)
		_inventory[i] = NULL;
	std::cout << "Character default constructor called for: " << _name << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < MAX_SLOTS; i++)
		_inventory[i] = NULL;
	std::cout << "Character name constructor called for: " << _name << std::endl;
}

Character::Character(const Character &copy)
{
	_name = copy._name;
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

// =========
// Operator Overload
// =========

Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		for (int i = 0; i < MAX_SLOTS; i++)
		{
			delete _inventory[i];
			if (copy._inventory[i])
				_inventory[i] = copy._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	std::cout << "Character assign operator called" << std::endl;
	return *this;
}

// =========
// Getters & Setters
// =========

const std::string &Character::getName() const { return _name; }

// =========
// Public member functions
// =========

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Couldnt equip NULL materia" << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Materia: " << _inventory[i]->getType() << " equiped successfully to index: " << i << std::endl;
			return ;
		}
		if (i == 3 && _inventory[i])
		{
			std::cout << "Inventory full" << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_SLOTS)
		std::cout << "Invalid idx given to Materia unequip: " << idx << std::endl;
	else
	{
		_inventory[idx] = NULL;
		std::cout << "Successfully removed Materia index: " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= MAX_SLOTS)
		std::cout << "Invalid idx given to Materia use: " << idx << std::endl;
	else if (_inventory[idx] == NULL)
		std::cout << "Inventory in :" << idx << " position is empty" << std::endl;
	else
		_inventory[idx]->use(target);
}

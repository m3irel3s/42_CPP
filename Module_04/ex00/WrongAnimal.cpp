#include "WrongAnimal.hpp"

// ==========
// Construcor & Destructor
// ==========

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called for " << _type << std::endl;
}

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Wrong Animal default constructor called for " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "Wrong Animal copy constructor called for " << _type << std::endl;
}

// ==========
// Operator Overload
// ==========

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

// ==========
// Public member functions
// ==========

void WrongAnimal::makeSound() const 
{
	std::cout << _type << " sound from Wrong Animal class" << std::endl;
}

// ==========
// Getters & setters
// ==========

std::string WrongAnimal::getType() const { return _type; }

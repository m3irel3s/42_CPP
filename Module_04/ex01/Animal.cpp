#include "Animal.hpp"

// ==========
// Constructor & Destructor
// ==========

Animal::~Animal()
{
	std::cout << "Animal destructor called for " << _type << std::endl;
}

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default construct called for " << _type << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal copy construct called for " << _type << std::endl;
}

// ==========
// Operator Overload
// ==========

Animal &Animal::operator=(const Animal &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

// ==========
// Getters & Setters
// ==========

std::string Animal::getType() const { return _type; }

// ==========
// Public Member Functions
// ==========

void Animal::makeSound() const 
{
	std::cout << _type << " sound from Animal class" << std::endl;
}

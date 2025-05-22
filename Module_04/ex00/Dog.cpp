#include "Dog.hpp"

// ==========
// Constructor & Destructor
// ==========

Dog::~Dog()
{
	std::cout << "Dog destructor called for " << _type << std::endl;
}

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog default constructor called for " << _type << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called for " << _type << std::endl;
}

// ==========
// Operator Overload
// ==========

Dog &Dog::operator=(const Dog &copy)
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

void Dog::makeSound() const
{
	std::cout << _type << " does woooof!" << std::endl;
}

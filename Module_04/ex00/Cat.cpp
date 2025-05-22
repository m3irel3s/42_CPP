#include "Cat.hpp"

// ==========
// Constructor & Destructor
// ==========

Cat::~Cat()
{
	std::cout << "Cat destructor called for " << _type << std::endl;
}

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat default constructor called for " << _type << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	*this = copy;
	std::cout << "Cat copy constructor called for " << _type << std::endl;
}

// ==========
// Operator Overload
// ==========

Cat &Cat::operator=(const Cat &copy)
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

void Cat::makeSound() const
{
	std::cout << _type << " does meoooow!" << std::endl;
}

#include "WrongCat.hpp"

// ==========
// Construcor & Destructor
// ==========

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called for " << _type << std::endl;
}

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "Wrong Cat default constructor called for " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "Wrong Cat copy constructor called for " << _type << std::endl;
}

// ==========
// Operator Overload
// ==========

WrongCat &WrongCat::operator=(const WrongCat &copy)
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

void WrongCat::makeSound() const
{
	std::cout << _type << " does wrong cat sound" << std::endl;
}

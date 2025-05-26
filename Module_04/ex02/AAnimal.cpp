#include "AAnimal.hpp"

// ==========
// Constructor & Destructor
// ==========

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called for " << _type << std::endl;
}

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default construct called for " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	*this = copy;
	std::cout << "AAnimal copy construct called for " << _type << std::endl;
}

// ==========
// Operator Overload
// ==========

AAnimal &AAnimal::operator=(const AAnimal &copy)
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

std::string AAnimal::getType() const { return _type; }

// ==========
// Public Member Functions
// ==========

void AAnimal::makeSound() const 
{
	std::cout << _type << " sound from Animal class" << std::endl;
}

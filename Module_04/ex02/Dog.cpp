#include "Dog.hpp"

// ==========
// Constructor & Destructor
// ==========

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called for " << _type << std::endl;
}

Dog::Dog() : AAnimal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called for " << _type << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	_type = copy._type;
	_brain = new Brain(*copy._brain);
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
		delete _brain;
		_brain = new Brain(*copy._brain);
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

// ==========
// Getters & Setters
// ==========

Brain *Dog::getBrain() const { return _brain; }

#include "Cat.hpp"

// ==========
// Constructor & Destructor
// ==========

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called for " << _type << std::endl;
}

Cat::Cat() : AAnimal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called for " << _type << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	_type = copy._type;
	_brain = new Brain(*copy._brain);
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
		delete _brain;
		_brain = new Brain(*copy._brain);
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

// ==========
// Getters & Setters
// ==========

Brain *Cat::getBrain() const { return _brain; }

#include "Ice.hpp"

// ===========
// Constructor & Destructor
// ===========

Ice::~Ice()
{
	std::cout << "Ice desctructor called" << std::endl;
}

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	*this = copy;
	std::cout << "Ice default constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}

// ===========
// Public member functions
// ===========

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

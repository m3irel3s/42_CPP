#include "Cure.hpp"

// ===========
// Constructor & Destructor
// ===========

Cure::~Cure()
{
	std::cout << "Cure desctructor called" << std::endl;
}

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	*this = copy;
	std::cout << "Cure default constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}

// ===========
// Public member functions
// ===========

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

#include "AMateria.hpp"

// =========
// Constructor & Destructor
// =========

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria()
{
	_type = "AMateria(Default)";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << "AMateria name constructor called for: " << _type << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	_type = copy._type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

// =========
// Operator Overload
// =========

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		_type = copy._type;
	std::cout << "AMateria assign operator called" << std::endl;
	return *this;
}

// =========
// Getters & Setters
// =========

std::string const &AMateria::getType() const { return _type; }

// =========
// Public member functions
// =========

void AMateria::use(ICharacter &target)
{
	static_cast<void>(target);
}

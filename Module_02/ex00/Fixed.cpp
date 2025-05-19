#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0){};

Fixed::~Fixed(){};

Fixed::Fixed(const Fixed &copy)
{
	_value = copy._value;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
	{
		_value = copy._value;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

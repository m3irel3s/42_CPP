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

Fixed::Fixed(const int value)
{
	_value = (value << _fractionalBits);
}

Fixed::Fixed(const float value)
{
	_value = (roundf(value * (1 << _fractionalBits)));
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
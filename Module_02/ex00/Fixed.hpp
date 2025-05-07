#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();

	private:
		int _value;
		static const int _fractionalBits;
};

#endif

#include "Fixed.hpp"

int main(void)
{
	Fixed test;
	Fixed test1;

	test.setRawBits(20);
	test1 = test;
	std::cout << test1.getRawBits() << std::endl;
}

/* // SUBJECT MAIN //
int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
} */
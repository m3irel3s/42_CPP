#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid input! Usage: ./ScavalarConverter <param>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
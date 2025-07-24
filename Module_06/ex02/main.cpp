#include "Base.hpp"

static void printSep();

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (size_t i = 0; i < 4; i++)
	{
		Base *randomClass = generate();

		printSep();
		std::cout << "Identifying with pointer: ";
		identify(randomClass);
		printSep();
		
		std::cout << "Identifying with reference: ";
		identify(*randomClass);
		printSep();

		delete randomClass;
	}
	return 0;
}

static void printSep()
{
	std::cout << "--------------------------\n";
}
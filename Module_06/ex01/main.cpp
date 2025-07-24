#include "Serializer.hpp"

static void printSep();

int main()
{
	Data original;

	original.n = 2;
	original.str = "Miguel";

	printSep();
	std::cout << "Original data:" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "Number: " << original.n << std::endl;
	std::cout << "String: " << original.str << std::endl;
	printSep();
	
	uintptr_t seriliaze = Serializer::serialize(&original);
	std::cout << "Serialize value: " << seriliaze << std::endl;
	printSep();
	
	Data *deserialize = Serializer::deserialize(seriliaze);
	
	std::cout << "Deserealized data:" << std::endl;
	std::cout << "Address: " << deserialize << std::endl;
	std::cout << "Number: " << deserialize->n << std::endl;
	std::cout << "String: " << deserialize->str << std::endl;
	printSep();


	if (deserialize == &original)
		std::cout << "Pointers are identical." << std::endl;

}
static void printSep()
{
	std::cout << "-----------------------------\n";
}

#include "easyfind.hpp"

static void printSep();

int main()
{
	std::vector<int> vec;

	printSep();
	for (size_t i = 0; i < 5; i++)
		vec.push_back(i * 2);

	std::cout << "Testing for std::vector" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 11);
		std::cout << "Value found: " << *it << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Value found: " << *it << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printSep();
	
	std::list<int> list;
	
	for (size_t i = 0; i < 5; i++)
		list.push_back(i * 3);

	std::cout << "Testing for std::list" << std::endl;

	try
	{
		std::list<int>::iterator it = easyfind(list, 9);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>::iterator it = easyfind(list, 10);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	printSep();
}

static void printSep()
{
	std::cout << "----------------------------------" << std::endl;
}
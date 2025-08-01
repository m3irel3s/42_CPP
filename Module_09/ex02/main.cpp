#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pmergeMe(argc, argv);

		pmergeMe.sortAndPrint();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
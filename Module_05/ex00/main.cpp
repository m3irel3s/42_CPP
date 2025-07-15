#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat miguel("Miguel", 150);
		std::cout << miguel << std::endl;
		miguel.incrementGrade();
		std::cout << miguel << std::endl;
		miguel.incrementGrade();
		std::cout << miguel << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

// static void printSep(void)
// {
// 	std::cout << "----------------------------------" << std::endl;
// }
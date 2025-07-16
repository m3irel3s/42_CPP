#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat miguel("Miguel", 99);
		ShrubberyCreationForm shrubbery("forest");
		shrubbery.execute();
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
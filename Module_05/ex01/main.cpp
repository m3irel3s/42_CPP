#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat miguel("Miguel", 99);
		Form form("miguel-form", 100, 100);
		miguel.signForm(form);
		std::cout << miguel << std::endl;
		std::cout << form << std::endl;
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
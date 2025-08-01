#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments given. Usage ./RPN \"<expression>\"" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn;

		int result = rpn.execute(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments, try ./btc <filename>" << std::endl;
		return 1;
	}
	BitcoinExchange test;
	try
	{
		test.parseData("data.csv");
		test.parseInput(std::string(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
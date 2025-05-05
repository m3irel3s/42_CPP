#include "SedLosers.hpp"

void	Replace(std::ifstream &file, char **argv);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Program must take 3 params" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Invalid file given" << std::endl;
		return 1;
	}
	Replace(file, argv);
	file.close();
	return 0;
}

void	Replace(std::ifstream &file, char **argv)
{

}
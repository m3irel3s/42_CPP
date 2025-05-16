#include "Harl.hpp"

static void HarlFilter(std::string level, Harl &harl);

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;

	if (argc != 2)
	{
		std::cout << "Invalid parameters given" << std::endl;
		std::cout << "Avaiable levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}

	level = argv[1];
	HarlFilter(level, harl);
	return 0;
}

static void HarlFilter(std::string level, Harl &harl)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			index = i;
	}

	switch (index)
	{
		case DEBUG:
			harl.complain(levels[index++]);
		case INFO:
			harl.complain(levels[index++]);
		case WARNING:
			harl.complain(levels[index++]);
		case ERROR:
			harl.complain(levels[index++]);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
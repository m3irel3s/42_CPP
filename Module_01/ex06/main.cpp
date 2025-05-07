#include "Harl.hpp"

static void HarlFilter(std::string level, Harl &harl);

int main(int argc, char **argv)
{
	(void)argv;
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
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case INFO:
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case WARNING:
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case ERROR:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
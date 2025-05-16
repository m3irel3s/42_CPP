#include "SedLosers.hpp"

static void Replace(std::ifstream &file, char **argv, std::string s1, std::string s2);

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
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.length() < 1 || s2.length() < 1)
	{
		std::cout << "Invalid arguments given" << std::endl;
		return 1;
	}

	Replace(file, argv, s1, s2);
	file.close();
	return 0;
}

static void Replace(std::ifstream &file, char **argv, std::string s1, std::string s2)
{
	std::string outFileName = std::string(argv[1]) + ".replace";
	std::ofstream outfile(outFileName.c_str());
	std::string line;

	while (std::getline(file, line))
	{
		std::string result;
		std::size_t pos = 0;
		std::size_t found;

		while ((found = line.find(s1, pos)) != std::string::npos)
		{
			result += line.substr(pos, found - pos);
			result += s2;
			pos = found + s1.length();
		}
		result += line.substr(pos);
		outfile << result << std::endl;
	}
}
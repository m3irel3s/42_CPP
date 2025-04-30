#include <iostream>
#include <string.h>

static void	ft_capitalize(char **argv);

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		ft_capitalize(argv);
}

static void	ft_capitalize(char **argv)
{
	for (int i = 1; argv[i]; i++)
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
	std::cout << std::endl;
}

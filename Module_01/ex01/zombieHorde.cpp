#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombiesArray = NULL;

	if (N <= 0)
		std::cout << "Invalid number of zombies given" << std::endl;
	else
	{
		zombiesArray = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			zombiesArray[i].setName(name);
			zombiesArray[i].announce();
		}
	}
	return zombiesArray;
}

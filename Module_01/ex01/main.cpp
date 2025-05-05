#include "Zombie.hpp"

int main(void)
{
	Zombie		*horde;
	int			n = 10;
	std::string	name = "Miguel";

	horde = zombieHorde(n, name);
	delete[] horde;
}

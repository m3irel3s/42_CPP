#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *zombiePtr;

	zombiePtr = new Zombie(name);
	return zombiePtr;
}

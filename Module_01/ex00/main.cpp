#include "Zombie.hpp"

Zombie::Zombie(){};

int	main(void)
{
	Zombie	miguel("Miguel");
	Zombie	*heap;

	heap = newZombie("Heap");
	miguel.anounce();
	heap->anounce();
	randomChump("Stack");
	delete(heap);
}

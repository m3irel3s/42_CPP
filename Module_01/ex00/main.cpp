#include "Zombie.hpp"

int	main(void)
{
	Zombie	miguel("Miguel");
	Zombie	*heap;

	heap = newZombie("Heap");
	miguel.announce();
	heap->announce();
	randomChump("Stack");
	delete(heap);
}

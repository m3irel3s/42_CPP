#include "Zombie.hpp"

Zombie::Zombie(){};

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destroyed: " << _name << std::endl;
}
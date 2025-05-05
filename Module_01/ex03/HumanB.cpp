#include "HumanB.hpp"

HumanB::~HumanB(){};

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

void HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << "Human B " << _name << " can't attack without a weapon" << std::endl;
	else
		std::cout << "Human B " << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
#include "HumanA.hpp"

HumanA::~HumanA(){};

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {};

void HumanA::attack(void)
{
	std::cout << "Human A " << _name << " attacks with their " << _weapon.getType() << std::endl;
}
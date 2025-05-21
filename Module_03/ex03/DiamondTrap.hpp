#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		~DiamondTrap();

		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &copy);

		DiamondTrap &operator=(const DiamondTrap &copy);

		void whoAmI();
		void attack(const std::string &target);

	private:
		std::string _name;

};


#endif
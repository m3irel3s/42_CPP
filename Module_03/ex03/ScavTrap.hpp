#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();

		ScavTrap(const ScavTrap &copy);
		ScavTrap(const std::string name);

		ScavTrap &operator=(const ScavTrap &copy);

		void guardGate();
		void attack(const std::string &taget);

	private:
};

#endif
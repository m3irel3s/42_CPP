#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();

		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

		ScavTrap &operator=(const ScavTrap &copy);

		void guardGate();
		void attack(const std::string &taget);

	private:
};

#endif
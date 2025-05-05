#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();

		void setType(std::string newType);
		const std::string &getType(void) const;

	private:
		std::string _type;
};

#endif
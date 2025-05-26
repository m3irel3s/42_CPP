#pragma once

#include "ICharacter.hpp"

#define MAX_SLOTS 4

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string &name);
		~Character();

		Character(const Character &copy);
		Character &operator=(const Character &copy);

		std::string const &getName() const;
		
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

	private:
		AMateria *_inventory[MAX_SLOTS];
		std::string _name;
};

#pragma once

#include <iostream>

class AMateria
{
	public:
		AMateria();
		virtual ~AMateria();

		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &copy);

		AMateria(std::string const &type);

		std::string const &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);

	private:
		std::string _type;

};
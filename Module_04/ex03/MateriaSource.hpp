#pragma once

#include "IMateriaSource.hpp"
#include "Character.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();

		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &copy);

		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
		AMateria *getMateria(std::string const &type);

	private:
		AMateria *_source[MAX_SLOTS];
};

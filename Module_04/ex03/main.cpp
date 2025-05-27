#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

#include <iostream>


static void printSep(void);

// =========
// Subject main
// =========

int main()
{
	IMateriaSource* src = new MateriaSource();
	printSep();
	src->learnMateria(new Ice());
	printSep();
	src->learnMateria(new Cure());
	printSep();
	ICharacter* me = new Character("me");
	printSep();
	AMateria* tmp;
	printSep();
	tmp = src->createMateria("ola");
	printSep();
	me->equip(tmp);
	printSep();
	tmp = src->createMateria("cure");
	printSep();
	me->equip(tmp);
	printSep();
	ICharacter* bob = new Character("bob");
	printSep();
	me->use(0, *bob);
	printSep();
	me->use(1, *bob);
	printSep();
	delete bob;
	printSep();
	delete me;
	printSep();
	delete src;
	printSep();
	return 0;
}

static void printSep(void)
{
	std::cout << "----------------------------------" << std::endl;
}
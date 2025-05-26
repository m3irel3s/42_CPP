#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Brain.hpp"

static void printSep(void);

int main()
{
	// AAnimal ola;
	AAnimal* animals[MAX_IDEAS];

	printSep();
	std::cout << "=== Creating 100 Animals ===" << std::endl;
	printSep();
	for (int i = 0; i < MAX_IDEAS; ++i)
	{
		if (i < MAX_IDEAS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	printSep();
	std::cout << "=== Woof and miauuu ===" << std::endl;
	printSep();
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		std::string type = animals[i]->getType();

		animals[i]->makeSound();
	}

	printSep();
	std::cout << "=== Cleaning Up === " << std::endl;
	printSep();
	for (int i = 0; i < MAX_IDEAS; ++i)
		delete animals[i];

	return 0;
}

static void printSep(void)
{
	std::cout << "----------------------------------" << std::endl;
}

// ======== 
// Subject Main
// ========

// int main(void)
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }
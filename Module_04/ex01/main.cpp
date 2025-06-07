#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Brain.hpp"

static void printSep(void);

int main() {
	Animal* animals[MAX_IDEAS];

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
	std::cout << "=== Giving Dog And Cat Ideas ===" << std::endl;
	printSep();
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		std::string type = animals[i]->getType();

		if (type == "Dog")
		{
			Brain* brain = static_cast<Dog*>(animals[i])->getBrain();
			for (int j = 0; j < MAX_IDEAS; j++)
				brain->setIdea(j, "Dog idea");
		}
		else if (type == "Cat")
		{
			Brain* brain = static_cast<Cat*>(animals[i])->getBrain();
			for (int j = 0; j < MAX_IDEAS; j++)
				brain->setIdea(j, "Cat idea");
		}
	}

	printSep();
	std::cout << "=== Printing Dog And Cat Ideas ===" << std::endl;
	printSep();
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		std::string type = animals[i]->getType();
		Brain* brain = NULL;

		if (type == "Dog")
			brain = static_cast<Dog*>(animals[i])->getBrain();
		else if (type == "Cat")
			brain = static_cast<Cat*>(animals[i])->getBrain();
		std::cout << type << " " << i << " idea: " << brain->getIdea(i) << std::endl;
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
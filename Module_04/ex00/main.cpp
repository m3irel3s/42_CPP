#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void printSep(void);

int main(void)
{
	const Animal *a = new Animal();
	const Animal *b = new Dog();
	const Animal *c = new Cat();
	printSep();

	std::cout << "Animal type: " << a->getType() << std::endl;
	a->makeSound();
	printSep();

	std::cout << "Dog type: " << b->getType() << std::endl;
	b->makeSound();
	printSep();

	std::cout << "Cat type: " << c->getType() << std::endl;
	c->makeSound();
	printSep();

	delete a;
	delete b;
	delete c;
	printSep();

	const WrongAnimal *d = new WrongAnimal();
	const WrongAnimal *e = new WrongCat();
	printSep();

	std::cout << "Wrong Animal type: " << d->getType() << std::endl;
	d->makeSound();
	printSep();

	std::cout << "Wrong Cat type: " << e->getType() << std::endl;
	e->makeSound();
	printSep();
	
	delete d;
	delete e;
}

static void printSep(void)
{
	std::cout << "----------------------------------" << std::endl;
}


// ======== 
// Subject Main
// ========

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	...
// 	return 0;
// }
#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		~Dog();

		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);

		void makeSound() const;

		Brain *getBrain() const;

	private:
		Brain *_brain;
};

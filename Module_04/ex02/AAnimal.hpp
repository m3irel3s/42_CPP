#pragma once

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal();

		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);

		std::string getType() const;

		virtual void makeSound() const = 0;

	protected:
		std::string _type;
};

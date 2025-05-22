#pragma once

#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();

		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);

		std::string getType() const;

		virtual void makeSound() const;

	protected:
		std::string _type;
};

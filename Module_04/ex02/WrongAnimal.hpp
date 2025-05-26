#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		virtual ~WrongAnimal();

		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);

		std::string getType() const;
		void makeSound() const;


	protected:
		std::string _type;
};

#include "Brain.hpp"

// ==========
// Constructor & Destructor
// ==========

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			_ideas[i] = copy._ideas[i];
	}
	return *this;
}


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

// ==========
// Operator Overload
// ==========

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			_ideas[i] = copy._ideas[i];
	}
	return *this;
}

// ==========
// Setters & Getters
// ==========

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index <= MAX_IDEAS)
		_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index <= MAX_IDEAS)
		return _ideas[index];
	return "";
}

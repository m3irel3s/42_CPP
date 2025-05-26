#pragma once

#include <iostream>

#define MAX_IDEAS 100

class Brain
{
	public:
		Brain();
		~Brain();

		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);

		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;

	private:
		std::string _ideas[MAX_IDEAS];
};
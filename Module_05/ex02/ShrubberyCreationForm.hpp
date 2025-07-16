#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		
		ShrubberyCreationForm(const std::string &target);

		virtual void execute() const;
		
	private:
		const std::string _target;
};

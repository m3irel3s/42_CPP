#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();

		Bureaucrat(const std::string &name, int grade);

		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);

		const std::string &getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		void signForm(Form &form);

	private:
		const std::string _name;
		int _grade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

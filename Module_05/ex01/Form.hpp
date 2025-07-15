#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		~Form();

		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		Form(const Form &copy);
		Form &operator=(const Form &copy);
		
		const std::string &getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;
		
		void beSigned(const Bureaucrat &bureaucrat);

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
		
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
};

std::ostream &operator<<(std::ostream &out, const Form &form);
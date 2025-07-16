#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		virtual ~AForm();

		AForm(const std::string &name, int gradeToSign, int gradeToExecute);

		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		
		const std::string &getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;
		
		void beSigned(const Bureaucrat &bureaucrat);

		void execute(const Bureaucrat &executor) const;
		virtual void execute() const = 0;

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

std::ostream &operator<<(std::ostream &out, const AForm &AForm);
#include "Form.hpp"

const int Form::MAX_GRADE;
const int Form::MIN_GRADE;

Form::Form() : _name("Default"), _signed(false), _gradeToSign(50), _gradeToExecute(100) {}

Form::~Form() {}

Form::Form(const Form &copy) :
	_name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign),
	_gradeToExecute(copy._gradeToExecute) {}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return *this;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) :
	 _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	if (gradeToExecute > MIN_GRADE || gradeToSign > MIN_GRADE)
		throw GradeTooLowException();
}

const std::string &Form::getName() const { return _name; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }
bool Form::isSigned() const { return _signed; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	std::cout << "Trying to sign: " << bureaucrat.getName() << std::endl;
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too High!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() 
	<< " Form, grade to sign is " << form.getGradeToSign()
	<< ", grade to execute is " << form.getGradeToExecute()
	<< " and is " << (form.isSigned() ? "signed." : "not signed.");
	return out;
}





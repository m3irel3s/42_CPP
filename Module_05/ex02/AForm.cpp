#include "AForm.hpp"

const int AForm::MAX_GRADE;
const int AForm::MIN_GRADE;

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(50), _gradeToExecute(100) {}

AForm::~AForm() {}

AForm::AForm(const AForm &copy) :
	_name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign),
	_gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return *this;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :
	 _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	if (gradeToExecute > MIN_GRADE || gradeToSign > MIN_GRADE)
		throw GradeTooLowException();
}

const std::string &AForm::getName() const { return _name; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
bool AForm::isSigned() const { return _signed; }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	std::cout << "Trying to sign: " << bureaucrat.getName() << std::endl;
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too High!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() 
	<< " AForm, grade to sign is " << AForm.getGradeToSign()
	<< ", grade to execute is " << AForm.getGradeToExecute()
	<< " and is " << (AForm.isSigned() ? "signed." : "not signed.");
	return out;
}





#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::setAll(std::string firstName, std::string lastName, std::string nickName,
	std::string darkestSecret, std::string phoneNumber){
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_nickName = nickName;
		this->_darkestSecret = darkestSecret;
		this->_phoneNumber = phoneNumber;
}

std::string	Contact::getFirstName() const
{
	return _firstName;
}

std::string	Contact::getLastName() const 
{
	return _lastName;
}

std::string	Contact::getNickName() const
{
	return _nickName;
}

std::string	Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

std::string	Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

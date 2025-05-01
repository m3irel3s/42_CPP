#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::SetAll(std::string firstName, std::string lastName, std::string nickName,
	std::string darkestSecret, std::string phoneNumber){
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_nickName = nickName;
		this->_darkestSecret = darkestSecret;
		this->_phoneNumber = phoneNumber;
}

std::string	Contact::GetFirstName() const
{
	return _firstName;
}

std::string	Contact::GetLastName() const 
{
	return _lastName;
}

std::string	Contact::GetNickName() const
{
	return _nickName;
}

std::string	Contact::GetDarkestSecret() const
{
	return _darkestSecret;
}

std::string	Contact::GetPhoneNumber() const
{
	return _phoneNumber;
}

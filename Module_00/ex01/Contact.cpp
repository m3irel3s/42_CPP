#include "Contact.hpp"

Contact::Contact(void){}
Contact::~Contact(void){}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName,
	std::string darkestSecret, int phoneNumber){
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_nickName = nickName;
		this->_darkestSecret = darkestSecret;
		this->_phoneNumber = phoneNumber;
}

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void setAll(std::string firstName, std::string lastName, std::string nickName,
				std::string darkestSecret, std::string phoneNumber);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getDarkestSecret() const;
		std::string	getPhoneNumber() const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkestSecret;
		std::string	_phoneNumber;
};

#endif

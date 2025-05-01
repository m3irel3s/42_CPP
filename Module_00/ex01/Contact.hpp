#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void SetAll(std::string firstName, std::string lastName, std::string nickName,
				std::string darkestSecret, std::string phoneNumber);

		std::string	GetFirstName() const;
		std::string	GetLastName() const;
		std::string	GetNickName() const;
		std::string	GetDarkestSecret() const;
		std::string	GetPhoneNumber() const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkestSecret;
		std::string	_phoneNumber;
};

#endif

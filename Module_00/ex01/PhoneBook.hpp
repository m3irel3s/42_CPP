#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook 
{
	public:
		PhoneBook();
		~PhoneBook();

		void	AddContact();
		void	SearchContact();

		void	FillContacts();

	private:
		Contact	_contacts[MAX_CONTACTS];
		size_t	_count;
};

#endif

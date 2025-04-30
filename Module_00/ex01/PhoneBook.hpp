#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook 
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
	private:
		Contact	_contacts[MAX_CONTACTS];
};

#endif

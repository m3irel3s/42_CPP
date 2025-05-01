#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_count = 0;
};

PhoneBook::~PhoneBook(){};

static std::string	TrimContactField(std::string str);
static void			PrintSearchMenu();

void PhoneBook::AddContact()
{
	std::string	firstName, lastName, nickName, darkestSecret, phoneNumber;
	size_t		index;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);

	index = _count % MAX_CONTACTS;

	if (firstName.length() < 1 || lastName.length() < 1 || nickName.length() < 1
	|| darkestSecret.length() < 1 || phoneNumber.length() < 1)
	{
		std::cout << "\n\tA contact cannot have an empty field!" << std::endl;
		return ;
	}

	_contacts[index].SetAll(firstName, lastName, nickName, darkestSecret,
	phoneNumber);
	_count++;

	std::cout << "\nContact added successfully!" << std::endl;
}

void PhoneBook::SearchContact()
{
	std::string	input;
	size_t		index;

	PrintSearchMenu();
	
	for (size_t i = 0; i < MAX_CONTACTS && i < _count; i++)
	{
		std::cout << "|" << std::setw(10) <<  i + 1 << "|";
		std::cout << std::setw(10) << TrimContactField(_contacts[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << TrimContactField(_contacts[i].GetLastName()) << "|";
		std::cout << std::setw(10) << TrimContactField(_contacts[i].GetNickName()) << "|";
		std::cout << std::endl;
	}

	std::cout << "\nEnter an index to search: ";
	std::getline(std::cin, input);
	
	if (input.length() == 1 && std::isdigit(input[0]))
	{
		index = input[0] - '0';
		if (index >= 1 && index <= _count)
		{
			std::cout << "\nFirst name: " << _contacts[index -1].GetFirstName() << std::endl;
			std::cout << "Last name: " << _contacts[index -1].GetLastName() << std::endl;
			std::cout << "Nickname: " << _contacts[index -1].GetNickName() << std::endl;
			std::cout << "Darkest secret: " << _contacts[index -1].GetDarkestSecret() << std::endl;
			std::cout << "Phone number: " << _contacts[index -1].GetPhoneNumber() << std::endl;
		}
		else
			std::cout << "\n\tIndex is out of range" << std::endl;
	}
	else
		std::cout << "\n\tInvalid input, enter a number between 1 and " << MAX_CONTACTS << std::endl;
}

static void	PrintSearchMenu()
{
	std::cout << "\n\t\tSEARCH MENU\n" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
}

static std::string	TrimContactField(std::string str)
{
	if(str.length() > 9)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void PhoneBook::FillContacts()
{
	const std::string names[8] = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Hank"};
	const std::string lastNames[8] = {"Smith", "Jones", "Taylor", "Brown", "White", "Black", "Green", "Clark"};
	const std::string nicknames[8] = {"Ace", "Bee", "Chuck", "Dee", "Ev", "Franky", "Gee", "Hankster"};
	const std::string secrets[8] = {
		"Loves pineapple on pizza", "Sleeps with light on", "Scared of clowns",
		"Hates rain", "Can't swim", "Afraid of heights", "Cries during movies", "Addicted to coffee"
	};
	const std::string phones[8] = {
		"1234567890", "2345678901", "3456789012", "4567890123",
		"5678901234", "6789012345", "7890123456", "8901234567"
	};

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		_contacts[i].SetAll(names[i], lastNames[i], nicknames[i],
			secrets[i], phones[i]);
	}
	_count = MAX_CONTACTS;
}

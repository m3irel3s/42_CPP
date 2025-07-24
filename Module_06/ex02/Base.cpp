#include "Base.hpp"

Base::~Base() {};

Base *generate(void)
{

	int random = std::rand() % 3;

	switch (random)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		return NULL;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	
	std::cout << "Unknown type" << std::endl;
}
#include "MutantStack.hpp"

void subject_main();
void test_main();

int main(void)
{
	subject_main();
	// test_main();
}

void test_main()
{
	MutantStack<int> mstack;

	std::cout << "Pushing values 1 to 10 onto the MutantStack" << std::endl;
	for (int i = 1; i <= 10; ++i)
		mstack.push(i);

	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Stack size: " << mstack.size() << "\n" << std::endl;

	std::cout << "Iterating from bottom to top:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n" << std::endl;

	std::cout << "Iterating from top to bottom (reverse):" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
}


void subject_main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}
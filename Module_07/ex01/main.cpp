#include "Iter.hpp"


int main()
{
	int intArr[5] = {1, 2, 3, 4, 5};
	iter(intArr, 5, printArr<int>);
	std::cout << std::endl;
	
	char charArr[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(charArr, 5, printArr<char>);
	std::cout << std::endl;
	
	float floatArr[5] = {10.5f, 20.5f, 100.3f, 1.5f, 0.5f};
	iter(floatArr, 5, printArr<float>);
	std::cout << std::endl;
}



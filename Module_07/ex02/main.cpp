#include "Array.hpp"

int main()
{
	try
	{
		Array<int> numArray(5);
		Array<char> charArray(5);

		// charArray[0] = 42;

		Array<char> charArray2(10);
	
		for (unsigned int i = 0; i < numArray.size(); i++)
			numArray[i] = i * 2;

		for (unsigned int i = 0; i < charArray.size(); i++)
			charArray[i] = 'a' + i;

		// charArray2 = charArray;
		
		std::cout << "Printing numArray" << std::endl;
		for (unsigned int i = 0; i < numArray.size(); i++)
			std::cout << "index[" << i << "] ->" << numArray[i] << std::endl;

		std::cout << "Printing charArray" << std::endl;
		for (unsigned int i = 0; i < charArray.size(); i++)
			std::cout << "index[" << i << "] ->" << charArray[i] << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
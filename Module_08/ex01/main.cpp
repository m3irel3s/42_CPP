#include "Span.hpp"

int main(void)
{
	std::cout << "Simple test" << std::endl;
	try
	{
		Span span(5);
		for (size_t i = 0; i < 5; i++)
			span.addNumber(i * 5);
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTesting using a range of iterators" << std::endl;
	try
	{
		Span span(10000);
		std::vector<int> range(10000);
		std::generate(range.begin(), range.end(), std::rand);
		span.fillWithIterators(range.begin(), range.end());
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nDemonstrating span full" << std::endl;
	try
	{
		Span span(3);
		span.addNumber(5);
		span.addNumber(1);
		span.addNumber(1);
		span.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nDemonstrating could not found span" << std::endl;
	try
	{
		Span span(3);
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
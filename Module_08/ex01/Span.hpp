#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span();
		~Span();

		Span(const Span &copy);
		Span &operator=(const Span &copy);

		Span(unsigned int maxSize);

		void addNumber(int number);
		void fillWithIterators(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int shortestSpan() const;
		int longestSpan() const;

		unsigned int getMaxSize() const;
		std::vector<int> getNumbers() const;

		class SpanFullException : public std::exception
		{
			const char *what() const throw();
		};

		class SpanNotFoundException : public std::exception
		{
			const char *what() const throw();
		};

	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
};

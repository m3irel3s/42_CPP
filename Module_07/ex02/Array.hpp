#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		~Array();

		Array(const Array &copy);
		Array &operator=(const Array &copy);

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		unsigned int size() const;

	private:
		unsigned int _arraySize;
		T *_data;

};

#include "Array.tpp"


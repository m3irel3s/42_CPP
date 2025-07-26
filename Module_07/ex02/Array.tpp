#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _data(NULL), _arraySize(0) {}

template<typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template<typename T>
Array<T>::Array(const Array &copy) : 
	_arraySize(copy._arraySize), _data(new T[copy._arraySize])
{
	for (unsigned int i = 0; i < _arraySize; i++)
	{
		_data[i] = copy._data[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
	if (this != &copy)
	{
		delete[] _data;
		_arraySize = copy._arraySize;
		_data = new T[_arraySize];
		for (unsigned int i = 0; i < _arraySize; i++)
		{
			_data[i] = copy._data[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::Array(const unsigned int n) : _arraySize(n)
{
	_data = new T[n]();
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _arraySize)
		throw IndexOutOfBoundsException();
	return _data[index];
}

template<typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _arraySize)
		throw IndexOutOfBoundsException();
	return _data[index];
}

template<typename T>
unsigned int Array<T>::size() const { return _arraySize; }

template<typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return "Index is out of bounds";
}



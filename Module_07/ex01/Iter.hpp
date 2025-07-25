#pragma once

#include <iostream>

template<typename T>
void iter(T *array, size_t arrayLength, void (*f)(const T &))
{
	if (!array || arrayLength <= 0 || !f)
	{
		std::cout << "Invalid array, array size or function passed" << std::endl;
		return ;
	}
	for (size_t i = 0; i < arrayLength; i++)
	{
		(*f)(array[i]);
	}
}

template<typename T>
void iter(T *array, size_t arrayLength, void (*f)(T &))
{
	if (!array || arrayLength <= 0 || !f)
	{
		std::cout << "Invalid array, array size or function passed" << std::endl;
		return ;
	}
	for (size_t i = 0; i < arrayLength; i++)
	{
		(*f)(array[i]);
	}
}


template<typename T>
void printArr(T &x)
{
	std::cout << x << " ";
}
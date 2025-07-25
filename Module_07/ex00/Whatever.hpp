#pragma once

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T &min(T &a, T &b)
{
	return (a < b ? a : b);
}

template<typename T>
T &max(T &a, T &b)
{
	return (a > b ? a : b);
}

// char max(char a, char b)
// {
// 	return (a > b ? a : b);
// }

// int max(int a, int b)
// {
// 	return (a > b ? a : b);
// }
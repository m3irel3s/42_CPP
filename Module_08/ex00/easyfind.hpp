#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	typename T::iterator it = find(container.begin(), container.end(), toFind);

	if (it == container.end())
	{
		throw std::runtime_error("Value was not found");
	}
	return it;
}

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <limits.h>
#include <cerrno>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);

		PmergeMe(int argc, char **argv);

		void sortAndPrint();

	private:
		void parseInput(int argc, char **argv);
		void checkAndAdd(const std::string &arg, std::set<int> &seen);

		void displayBefore();
		void displayAfter();

		void mergeInsertVector();
		void mergeInsertDeque();

		static void binaryInsertVector(std::vector<int>& sorted, int value);
		static void binaryInsertDeque(std::deque<int>& sorted, int value);

		std::vector<int> _vector;
		std::deque<int> _deque;
};
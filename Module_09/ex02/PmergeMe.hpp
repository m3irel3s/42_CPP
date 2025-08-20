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

		std::vector<int> jacobsthalSequence(int size);
		std::vector<int> generateInsertionOrder(int size);

		void parseInput(int argc, char **argv);
		void checkAndAdd(const std::string &arg, std::set<int> &seen);

		void displayBefore();
		void displayAfter();

		void fordJohnsonVector(std::vector<int> &vec);
		void fordJohnsonDeque(std::deque<int> &deque);

		static void binaryInsertVector(std::vector<int> &arr, int value);
		static void binaryInsertDeque(std::deque<int> &arr, int value);

		std::vector<int> _vector;
		std::deque<int> _deque;
};
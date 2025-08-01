#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	_vector = copy._vector;
	_deque = copy._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_vector = copy._vector;
		_deque = copy._deque;
	}
	return *this;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	parseInput(argc, argv);
}

void PmergeMe::parseInput(int argc, char **argv)
{
	std::set<int> seen;

	for (int i = 1; i < argc; i++)
		checkAndAdd(argv[i], seen);
}

void PmergeMe::checkAndAdd(const std::string &arg, std::set<int> &seen)
{
	if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Error: not a number ");
	
	char *endptr;
	errno = 0;
	long val = std::strtol(arg.c_str(), &endptr, 10);
	if (val <= 0 || val > INT_MAX || errno == ERANGE || *endptr != '\0')
		throw std::runtime_error("Error: value is to low or to high");
	
	int num = static_cast<int>(val);
	if (!seen.insert(num).second)
		throw std::runtime_error("Error: duplicate numbers not allowed");
	
	_vector.push_back(num);
	_deque.push_back(num);
}

void PmergeMe::sortAndPrint()
{
	displayBefore();

	clock_t startVector = clock();
	mergeInsertVector();
	clock_t endVector = clock();
	double durationVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1e6;

	clock_t startDeque = clock();
	mergeInsertDeque();
	clock_t endDeque = clock();
	double durationDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1e6;

	displayAfter();

	std::cout << "Time to process a range of " << _vector.size() 
		<< " elements with std::vector: " << durationVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() 
		<< " elements with std::deque: " << durationDeque << " us" << std::endl;
}

void PmergeMe::mergeInsertVector() {
	if (_vector.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> sorted;

	// Step 1: Create and normalize pairs
	for (size_t i = 0; i + 1 < _vector.size(); i += 2) {
		int a = _vector[i];
		int b = _vector[i + 1];
		if (a < b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		pairs.push_back(std::make_pair(a, b));
	}

	// Step 2: Insert all the "greater" (first) values
	for (size_t i = 0; i < pairs.size(); ++i)
		sorted.push_back(pairs[i].first);

	std::sort(sorted.begin(), sorted.end());

	// Step 3: Binary insert the "lesser" (second) values
	for (size_t i = 0; i < pairs.size(); ++i)
		binaryInsertVector(sorted, pairs[i].second);

	// Step 4: Handle leftover element if size is odd
	if (_vector.size() % 2 == 1)
		binaryInsertVector(sorted, _vector.back());

	_vector = sorted;
}

void binaryInsertVector(std::vector<int>& sorted, int value)
{
	std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

void PmergeMe::mergeInsertDeque() {
	if (_deque.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	std::deque<int> sorted;

	for (size_t i = 0; i + 1 < _deque.size(); i += 2) {
		int a = _deque[i];
		int b = _deque[i + 1];
		if (a < b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		pairs.push_back(std::make_pair(a, b));
	}

	for (size_t i = 0; i < pairs.size(); ++i)
		sorted.push_back(pairs[i].first);

	std::sort(sorted.begin(), sorted.end());

	for (size_t i = 0; i < pairs.size(); ++i)
		binaryInsertDeque(sorted, pairs[i].second);

	if (_deque.size() % 2 == 1)
		binaryInsertDeque(sorted, _deque.back());

	_deque = sorted;
}

void binaryInsertDeque(std::deque<int>& sorted, int value)
{
	std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

void PmergeMe::displayBefore()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::displayAfter()
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}
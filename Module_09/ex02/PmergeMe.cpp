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
	fordJohnsonVector(_vector);
	clock_t endVector = clock();
	double durationVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1e6;

	clock_t startDeque = clock();
	fordJohnsonDeque(_deque);
	clock_t endDeque = clock();
	double durationDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1e6;

	displayAfter();

	std::cout << "Time to process a range of " << _vector.size() 
		<< " elements with std::vector: " << durationVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() 
		<< " elements with std::deque: " << durationDeque << " us" << std::endl;
}

// J(N) = J(N -1) + 2 * J(N -2)
// J(2) = J(1) + 2 * J(0) = 1 + 2 * 0 = 1. 
// J(3) = J(2) + 2 * J(1) = 1 + 2 * 1 = 3. 
// J(4) = J(3) + 2 * J(2) = 3 + 2 * 1 = 5. 
// J(5) = J(4) + 2 * J(3) = 5 + 2 * 3 = 11. 
// {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, ...}

std::vector<int> PmergeMe::jacobsthalSequence(int size)
{
	std::vector<int> jacNumbers;
	int a = 0;
	int b = 1;
	while (b < size)
	{
		jacNumbers.push_back(b);
		int next = b + 2 * a;
		a = b;
		b = next;
	}
	return jacNumbers;
}

std::vector<int> PmergeMe::generateInsertionOrder(int size)
{
	std::vector<int> order;
	std::vector<int> jac = jacobsthalSequence(size);
	std::vector<bool> selected(size, false);

	for (size_t i = 0; i < jac.size(); ++i)
	{
		if (!selected[jac[i]])
		{
			order.push_back(jac[i]);
			selected[jac[i]] = true;
		}
	}
	for (int i = 0; i < size; ++i)
	{
		if (!selected[i])
			order.push_back(i);
	}
	return order;
}

void PmergeMe::fordJohnsonVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> leftovers;

	// Create and normalize pairs
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	// Handling odd size
	if (vec.size() % 2 == 1)
		leftovers.push_back(vec.back());

	// Separate larger and smaller elements
	std::vector<int> larger;
	std::vector<int> smaller;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		larger.push_back(pairs[i].first);
		smaller.push_back(pairs[i].second);
	}

	fordJohnsonVector(larger);

	std::vector<int> mainChain = larger;

	std::vector<int> order = generateInsertionOrder(smaller.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t index = order[i];
		if (index < smaller.size())
			binaryInsertVector(mainChain, smaller[index]);
	}

	for (size_t i = 0; i < leftovers.size(); i++)
		binaryInsertVector(mainChain, leftovers[i]);

	vec = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &deque)
{
	if (deque.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> leftovers;

	// Create and normalize pairs
	for (size_t i = 0; i + 1 < deque.size(); i += 2)
	{
		int a = deque[i];
		int b = deque[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	// Handling odd size
	if (deque.size() % 2 == 1)
		leftovers.push_back(deque.back());

	// Separate larger and smaller elements
	std::deque<int> larger;
	std::deque<int> smaller;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		larger.push_back(pairs[i].first);
		smaller.push_back(pairs[i].second);
	}

	fordJohnsonDeque(larger);

	std::deque<int> mainChain = larger;

	std::vector<int> order = generateInsertionOrder(smaller.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t index = order[i];
		if (index < smaller.size())
			binaryInsertDeque(mainChain, smaller[index]);
	}

	for (size_t i = 0; i < leftovers.size(); i++)
		binaryInsertDeque(mainChain, leftovers[i]);

	deque = mainChain;
}

void PmergeMe::binaryInsertVector(std::vector<int> &vec, int value)
{
	size_t left = 0;
	size_t right = vec.size();

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (value < vec[mid])
			right = mid;
		else
			left = mid + 1;
	}
	vec.insert(vec.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int> &deque, int value)
{
	size_t left = 0;
	size_t right = deque.size();

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (value < deque[mid])
			right = mid;
		else
			left = mid + 1;
	}
	deque.insert(deque.begin() + left, value);
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
#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::~Span() {}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_maxSize = copy._maxSize;
		_numbers = copy._numbers;
	}
	return *this;
}

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

void Span::fillWithIterators(std::vector<int>::iterator begin,
	 std::vector<int>::iterator end)
{
	unsigned int distance = std::distance(begin, end);

	if (_numbers.size() + distance > _maxSize)
		throw SpanFullException();

	_numbers.insert(_numbers.end(), begin, end);
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw SpanNotFoundException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int longest = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int current = std::abs(sorted[i] - sorted[i - 1]);
		if (current > longest)
			longest = current;
	}
	return longest;
}

int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw SpanNotFoundException();
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int shortest = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int current = std::abs(sorted[i] - sorted[i - 1]);
		if (current < shortest)
			shortest = current;
	}
	return shortest;
}	

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full, no more numbers can be added.";
}

const char *Span::SpanNotFoundException::what() const throw()
{
	return "Not enough numbers to find a span.";
}

unsigned int Span::getMaxSize() const { return _maxSize; }
std::vector<int> Span::getNumbers() const { return _numbers; }


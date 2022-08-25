#include <algorithm>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "span.hpp"

Span::Span(void) : _numbers(NULL), _size(0), _usedSpace(0) { }

Span::Span(unsigned int const size) : _numbers(NULL), _size(size), _usedSpace(0)
{
	if (_size == 0)
		throw std::invalid_argument("cannot create span of size 0");
	_numbers = new int[_size];
}

Span::Span(Span const &rhs) : _numbers(NULL)
{
	*this = rhs;
}

Span::~Span(void)
{
	if (_numbers != NULL)
		delete []_numbers;
}

Span	&Span::operator=(Span const &rhs)
{
	if (_numbers != NULL)
		delete []_numbers;
	_numbers = NULL;
	_size = rhs.size();
	_usedSpace = rhs.length();
	if (_size == 0)
		throw std::invalid_argument("cannot create span of size 0");
	_numbers = new int[_size];
	for (unsigned int i = 0; i < _size; i++)
		_numbers[i] = rhs[i];
	return *this;
}

int	Span::operator[](unsigned int const index) const
{
	if (_size == 0 || index >= _size)
		throw std::out_of_range("accessed value on span of size 0 or out of bounds");
	return _numbers[index];
}

unsigned int	Span::size(void) const
{
	return _size;
}

unsigned int	Span::length(void) const
{
	return _usedSpace;
}

void	Span::addNumber(int const number)
{
	if (_size == _usedSpace)
		throw std::length_error("span reached maximum capacity");
	_numbers[_usedSpace] = number;
	_usedSpace++;
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

unsigned long	Span::shortestSpan(void) const
{
	int copyNumbers[_usedSpace];
	int result[_usedSpace - 1];

	if (_usedSpace < 2)
		throw std::underflow_error("span shortestSpan requires at least two numbers");
	std::copy(_numbers, _numbers + _usedSpace, copyNumbers);
	std::sort(copyNumbers, copyNumbers + _usedSpace);
	std::transform(copyNumbers + 1, copyNumbers + _usedSpace, copyNumbers, result, std::minus<int>());
	return *std::min_element(result, result + _usedSpace);
}

unsigned long	Span::longestSpan(void) const
{
	int copyNumbers[_usedSpace];

	if (_usedSpace < 2)
		throw std::underflow_error("span longestSpan requires at least two numbers");
	std::copy(_numbers, _numbers + _usedSpace, copyNumbers);
	std::sort(copyNumbers, copyNumbers + _usedSpace);
	return *(copyNumbers + _usedSpace - 1) - *copyNumbers;
}
